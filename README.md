Butterfly-ultimatic-single-lever-morse
======================================

C code for emulator between iambic paddle and morse keyer, AVR Butterfly

This is the code for the blog post "Single-lever and ultimatic adapter". 
http://la3za.blogspot.co.uk/2014/01/single-lever-and-ultimatic-adapter.html


Here is the main C-code routine for the adapter which has three modes:
Input is a dual-lever paddle and it is used to emulate in

Keyer = 0: Direct mode, for direct coupling between input and output (i.e. iambic)

Keyer = 1: Ultimatic mode 

Keyer = 2: Single-lever emulation

