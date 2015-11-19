/***************************************************************
 * Frequencies for an entire piano keyboard. We pulled this info
 * from this website:
 * http://www.phy.mtu.edu/~suits/notefreqs.html
 * 
 * Note names are organized by octave and sharp (s) or flat (b).
 *
 * Note: #define is a pre-compiler directive, so on the first pass
 * through your code, the compiler will replace anything that
 * has a #define statement associated with it with the appropriate
 * string or value. 
 *
 * Notice that #define does not use an '=' or a ';' mark.
 *
 * It's convenient because it doesn't use up any processor resources 
 * and the math is done by the compiling computer rather than on
 * the Arduino.
 * 
 ***************************************************************/
#define beatLength 200  // # of milliseconds per beat

// Define the length of each note
#define WN   beatLength*4  // ...a whole note...
#define HN   beatLength*2  // ...a half note...
#define QN   beatLength    // ...a quarter note...
#define EN   beatLength/2  // ...an eighth note...
#define SN   beatLength/4  // ...and a sixteenth note.

// These are pre-written #defines for every note on a piano
#define Rest 0
#define nC0 16
#define nCs0 17
#define nDb0 17
#define nD0 18
#define nDs0 19
#define nEb0 19
#define nE0 21
#define nF0 22
#define nFs0 23
#define nGb0 23
#define nG0 25
#define nGs0 26
#define nAb0 26
#define nA0 28
#define nAs0 29
#define nBb0 29
#define nB0 31
#define nC1 33
#define nCs1 35
#define nDb1 35
#define nD1 37
#define nDs1 39
#define nEb1 39
#define nE1 41
#define nFb1 41
#define nF1 44
#define nFs1 46
#define nGb1 46
#define nG1 49
#define nGs1 52
#define nAb1 52
#define nA1 55
#define nAs1 58
#define nBb1 58
#define nB1 62
#define nC2 65
#define nCs2 69
#define nDb2 69
#define nD2 73
#define nDs2 78
#define nEb2 78
#define nE2 82
#define nF2 87
#define nFs2 93
#define nGb2 93
#define nG2 98
#define nGs2 104
#define nAb2 104
#define nA2 110
#define nAs2 117
#define nBb2 117
#define nB2 123
#define nC3 131
#define nCs3 139
#define nDb3 139
#define nD3 147
#define nDs3 156
#define nEb3 156
#define nE3 165
#define nF3 175
#define nFs3 185
#define nGb3 185
#define nG3 196
#define nGs3 208
#define nAb3 208
#define nA3 220
#define nAs3 233
#define nBb3 233
#define nB3 247
#define nC4 262
#define nCs4 277
#define nDb4 277
#define nD4 294
#define nDs4 311
#define nEb4 311
#define nE4 330
#define nF4 349
#define nFs4 370
#define nGb4 370
#define nG4 392
#define nGs4 415
#define nAb4 415
#define nA4 440
#define nAs4 466
#define nBb4 466
#define nB4 494
#define nC5 523
#define nCs5 554
#define nDb5 554
#define nD5 587
#define nDs5 622
#define nEb5 622
#define nE5 659
#define nF5 698
#define nFs5 740
#define nGb5 740
#define nG5 784
#define nGs5 831
#define nAb5 831
#define nA5 880
#define nAs5 932
#define nBb5 932
#define nB5 988
#define nC6 1047
#define nCs6 1109
#define nDb6 1109
#define nD6 1175
#define nDs6 1245
#define nEb6 1245
#define nE6 1319
#define nF6 1397
#define nFs6 1480
#define nGb6 1480
#define nG6 1568
#define nGs6 1661
#define nAb6 1661
#define nA6 1760
#define nAs6 1865
#define nBb6 1865
#define nB6 1976
#define nC7 2093
#define nCs7 2217
#define nDb7 2217
#define nD7 2349
#define nDs7 2489
#define nEb7 2489
#define nE7 2637
#define nF7 2794
#define nFs7 2960
#define nGb7 2960
#define nG7 3136
#define nGs7 3322
#define nAb7 3322
#define nA7 3520
#define nAs7 3729
#define nBb7 3729
#define nB7 3951
#define nC8 4186
#define nCs8 4435
#define nDb8 4435
#define nD8 4699
#define nDs8 4978
#define nEb8 4978
