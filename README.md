HuffZip – Huffman Coding Text Compression Tool
A simple C++ implementation of Huffman Coding used for lossless text compression.
This project takes an input string, generates Huffman codes for each character, and compares the size of the original ASCII binary with the compressed binary output.

📌 Features
Builds a Huffman Tree based on character frequency
Generates prefix-free Huffman codes
Converts each character into 8-bit ASCII binary
Produces compressed binary using Huffman encoding
Displays:
Huffman codes for each character
Original 8-bit binary representation
Compressed binary sequence
Compression ratio

🧠 How It Works
Count frequency of each character in the input text
Construct a min-heap and build the Huffman Tree
Generate binary codes for each character
Encode the text using these codes
Compare original vs. compressed bit size

🛠️ Technologies Used
C++
STL Containers:
priority_queue
unordered_map
vector
bitset for ASCII to binary conversion
