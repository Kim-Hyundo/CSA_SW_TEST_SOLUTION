This is a small demo how to use the CombiProbe together with the 
ITM together with a CustomTrace DLL, which tells TRACE32 what
functions where called.


The "sieve.elf" program here, was created with a GNU compiler.
The GNU compiler offers the option to instrument all
function entries and exits.
In this demo the corresponding information (entry and return addresses)
is output via the ITM.

A custom DLL is used to interpret the received ITM data as
function entries and exits.
TRACE32 uses this information from the DLL to display a function chart.


To run the demo, please run k60n512_itm_custom_trace.cmm

After about 5s of execution the demo shows a 
   ca.ct.myfunc.chart
window which shows a function chart.

To generate this chart, TRACE32 passes the ITM data on to the 
func_inst DLL (source code in the sieve_ins/dll subdirectory).

The DLL was loaded under the name "MYFUNC", which then allows you
to open the "CAnalyzer.CustomTrace.MYFUNC.Chart" window.

