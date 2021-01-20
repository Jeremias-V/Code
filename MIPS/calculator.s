# Simple MIPS Calculator
# by Jeremias Villalobos

.data

msg1: .asciiz "\n=====================================================================================\nSelect the operator ('a+b': 0, 'a-b': 1, 'a*b': 2, 'a/b': 3, 'a%b': 4, 'exit': -1): "
msg2: .asciiz "Type the first number (a): "
msg3: .asciiz "Type the second number (b): "
msg4: .asciiz "The answer is: "
msg5: .asciiz "\nExiting the calculator...\n"

.text


readOP:

    # print msg1
    li      $v0, 4
    la      $a0, msg1       # load address of message
    syscall
    
    # read operator
    li      $v0, 5          # read int input
    syscall
    add     $s0, $0, $v0    # save input at $s0

    addi    $s1, $0, 0      # $s1 = sum code
    beq     $s0, $s1, sum   # if($s0 == $s1) go to sum

    addi    $s1, $0, 1          # $s1 = subtract code
    beq     $s0, $s1, subtract  # if($s0 == $s1) go to subtract
    
    addi    $s1, $0, 2          # $s1 = multiply code
    beq     $s0, $s1, multiply  # if($s0 == $s1) go to multiply

    addi    $s1, $0, 3          # $s1 = divide code
    beq     $s0, $s1, divide    # if($s0 == $s1) go to divide

    addi    $s1, $0, 4          # $s1 = percent code
    beq     $s0, $s1, percent   # if($s0 == $s1) go to percent

    addi    $s1, $0, -1     # $s1 = exit code
    beq     $s0, $s1, exit  # if($s0 == $s1) go to exit

    j       readOP          # if none of the above, ask again.

readAB:

    # print msg2
    li      $v0, 4
    la      $a0, msg2       # load address of message
    syscall

    # read input2
    li      $v0, 5          # read int input
    syscall
    add     $s2, $0, $v0    # save input 'a' at $s2

    # print msg2
    li      $v0, 4
    la      $a0, msg3       # load address of message
    syscall

    # read input2
    li      $v0, 5          # read int input
    syscall
    add     $s3, $0, $v0    # save input 'b' at $s3

    jr      $ra             # go back to operator function

printOutput:

    # answer is at $s4

    # print msg4
    li      $v0, 4
    la      $a0, msg4       # load address of message
    syscall

    # print answer
    li      $v0, 1          
    add     $a0, $s4, $0
    syscall

    j       readOP

sum:

    jal     readAB          # go to read a, b and $s2 = a, $s3 = b
    add     $s4, $s2, $s3   # $s4 = $s2 + $s3
    j       printOutput     # print $s4

subtract:

    jal     readAB          # go to read a, b and $s2 = a, $s3 = b
    sub     $s4, $s2, $s3   # $s4 = $s2 - $s3
    j       printOutput     # print $s4

multiply:

    jal     readAB          # go to read a, b and $s2 = a, $s3 = b
    mult    $s2, $s3        
    mflo    $s4             # $s4 = $s2 * $s3
    j       printOutput     # print $s4

divide:

    jal     readAB          # go to read a, b and $s2 = a, $s3 = b
    div     $s2, $s3        
    mflo    $s4             # $s4 = $s2 / $s3
    j       printOutput     # print $s4

percent:

    jal     readAB          # go to read a, b and $s2 = a, $s3 = b
    mult    $s2, $s3        
    mflo    $s6             # $s6 = $s2 * $s3
    addi    $s5, $0, 100    # to divide $s6
    div     $s6, $s5
    mflo    $s4             # $s4 = ($s2 * $s3) / 100
    j       printOutput     # print $s4

main:

    j       readOP

exit:

    # print msg5
    li      $v0, 4
    la      $a0, msg5       # load address of message
    syscall
    li      $v0, 10         # load exit code
    syscall                 # call exit code

.end