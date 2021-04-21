#include <iostream>
#include <fstream>
#include <string>

typedef struct wav_header {
    // RIFF Header
    char riff_header[4]; // Contains "RIFF"
    int wav_size; // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8
    char wave_header[4]; // Contains "WAVE"

    // Format Header
    char fmt_header[4]; // Contains "fmt " (includes trailing space)
    int fmt_chunk_size; // Should be 16 for PCM
    short audio_format; // Should be 1 for PCM. 3 for IEEE Float
    short num_channels;
    int sample_rate;
    int byte_rate; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
    short sample_alignment; // num_channels * Bytes Per Sample
    short bit_depth; // Number of bits per sample

    // Data
    char data_header[4]; // Contains "data"
    int data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size
    // char bytes[]; // Remainder of wave file is bytes
} wav_header;

int main(){
	std::string f = "testing.wav";
	std::ifstream file(f,std::ios::binary | std::ios::in);
	std::cout << sizeof(wav_header) << std::endl;
	
	wav_header waveHeader;
	
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
	}
	file.close();
	
	std::cout << waveHeader.audio_format << std::endl;
	std::cout << waveHeader.bit_depth << std::endl;
	
	
	return 0;
}
