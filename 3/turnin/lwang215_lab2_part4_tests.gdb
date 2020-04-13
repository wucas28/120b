# Test file for "3"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:

# Add tests below
# Example test:
# Report on how many tests passed/tests ran

test "PINA: 0x0A  => PORTC: 0xA0"
# # Set inputs
setPINA 0x0A
#  Continue for several ticks
continue 2
# # # Set expect values
expectPORTC 0xA0
# # Check pass/fail
checkResult


test "PINA: 0x3F => PORTC: 0xF0 PORTB: 0x03"
setPINA 0x3F
continue 2
expectPORTC 0xF0
expectPORTB 0x03
checkResult
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
