# CS 202 (PT47) Final Semester Project

## Group Members
Andrew Gorum, Jason Mills, Jared White

## Responsibilites Taken By Each Member
**Andrew G.**  
1. 16Bit Processing
2. Reading Metadata

**Jason M.** 
1. Reading in Audio Information  
2. Reading Metadata

**Jared W.**  
1. Doxygen
2. UML Diagrams

## UML Diagrams and Design Desc.
![Class Diagram](/class-diagram.png)

### Design Desc
This program allows the user to process a 8-bit or 16-bit audio. The user can perform noise gating, echo, or normalization to an 8-bit or 16-bit, mono or stereo, audio file. The user is able to modify the metadata and can export a CSV file with the metadata if they choose to do so.  


#### Echo
The `Echo` class allows the user to process their audio file (either 8-bit or 16-bit) and add an echo. The user can input a specific `delay` that will determine how long it will take the next set of audio to play, causing an echo effect.

#### Normalizer
The `Normalizer` class allows the user to process their audio file (either 8-bit or 16-bit) and normalize the audio; in layman's terms, the user can select a max value for its audio, and any audio that does not either reach that value, or exceeds that value, will be set to equal the user's inputted max value. This causes the audio to have the same volume throughout the file.

#### NoiseGate
The `NoiseGate` class allows the user to process their audio file (either 8-bit or 16-bit) and elimiate sound that is below the given threshold. For example, background noise that does not meet the given threshold will be removed from the audio file. 

#### FileGetter
The `FileGetter` class allows the user to get files from a string directory.

####  LoadBuffer
The `LoadBuffer` class reads the file selected by the user and determines whether or not the selected file  contains 8-bit or 16-bit audio. It then writes the file according to its bit depth and loads the according buffer.

## Problems Encountered
* Issues with reading and storing metadata, thus issues with exporting the CSV file
* - Binary files cannot be seen like text files, making understanding them difficult
* - Metadata format was an unknown and existing documentation for it was hard to understand
* - Metadada could not easilty be read in with a struct, causing bulky code
* - Metadata was not easy to write, causing bulky code
* Difficulty getting Doxygen to install
* Difficulty getting Doxygen to generate inheritance and collaboration charts
* Difficulty adapting pre-existing processors to work for 16-bit audio
* Difficulty reading in files from different directories
