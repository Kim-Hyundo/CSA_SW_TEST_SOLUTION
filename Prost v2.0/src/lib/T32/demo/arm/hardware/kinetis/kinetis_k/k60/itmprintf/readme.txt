This is a small demo how to use the CombiProbe together with the 
ITM in a simple fashion to output "printf" style data.

To run the demo, please run k60n512_trace_itmprintf.cmm

The DLL is used to display the "printf" style data

The "logger" window, is used by the DLL to output data via
  CAnalyzer.PipePROTO.LOG

You will see the "printfs" produced by the program in the logger window.

Additionally after you stop the recording, you are able to display all the logged
strings via
  CAnalyzer.CustomTrace.printf.List

This window can be used like any other trace window; in particular, the window
contains timing information, which makes it possible to correlate the displayed
strings to whatever other traces you are viewing (via the "/TRACK" option).


Note: This is only a very simple demo to show how to extend the TRACE32 tracing
functionality via your own DLL.
Of course you might modify and extend the DLL source code in any way you like.
