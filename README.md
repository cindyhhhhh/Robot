# Robot

Problem Description:

Robert is a farmer. He has a farm represented by an n × m grid. Each cell has unlimited nuts and each nut has its sweetness. Moreover, all nuts in the same cell have the same sweetness.
Robert would like to harvest some nuts, so he tries to control his robot named “Robot1003” to complete this mission. Initially, Robot1003 is at the top-left corner of the farm. Robert can only control Robot1003 to move right or down to the next cell in that direction. When Robot1003 is in a cell, it must take one nut from that cell. Besides, Robert has k space machines that can each be only used once. Once he uses up one space machine, he can make Robot1003 jump to any cell in the farm, including the current one.
However, every time a space machine is used, each nut in the farm will have its sweetness decreased by a constant c. Note that the sweetness may drop to a negative value. Robert can stop this process only when Robot1003 reaches the bottom-right corner of the farm. He hopes that the total sweetness harvested by Robot1003 can be as high as possible. Please help Robert calculate the optimal way of controlling Robot1003 to maximize the total sweetness.


Input:

Thefirstlinecontainsfourintegersn,m,k,andc(1≤n,m≤500, 0≤k≤10, 1≤c≤109), denoting the numbers of rows and columns in the farm, the number of space machines Robert has, and the constant subtracted from the sweetness values when using a space machine.
In the next n lines, the i-th contains m integers. The j-th integer aij (−109 ≤ aij ≤ 109) represents the initial sweetness of nuts in the cell (i,j). (0 ≤ i < n,0 ≤ j < m)

        
Output:

The first line of the output contains an integer, denoting the maximal sweetness that can be harvested by Robot1003.
The second line contains an integer s, denoting the number of moves throughout the process. In the next s lines, the i-th line represents the i-th move. For each move, if Robert should use the space machine on that step, output the word “Jump”; otherwise, output “Move”. After that, output two integers representing the coordinates Robot1003 will be at after the i-th move.
If there are multiple ways to control Robot1003 to maximize the total sweetness, you can output any one of them.
