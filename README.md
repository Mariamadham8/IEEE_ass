# i learned some commands in git & githup
#week2:some concepts about embedded systerms /
# in general the main components of a cpu ,ram,i/o and many cascadded componants to produce what we know today

![computer_parts](https://github.com/Mariamadham8/gitrepo/assets/121618861/8b46bb14-553f-4582-bbef-18c2180bba8a)

this componants are linked together to transfere the data by a bus which is like a medum the signal (data) go through it from deivce to another
==>there is 3 types of busses :1) data bus:responsble for transfering data from memory to i/o or to cpu 
2)address bus:contain addresses to make a communication between the cpu and the ram as the processed data loadded into a buffer and stores in a specified address in memory
3) controle bus: by logic as the control unit in cpu we need to manage all the processes and by the way there is many ways to communicating through a bus i can be :
. sync : which the the part who need to gain the controle of the bus send a request then the part who recieve will aknowladge this request this type has a clock controled by the system bus 
.asynch : this type has no timer the sender will send a request until the other side respond with aknowldment and vise versa

..............................................so the  question now how my cute code will deal with all this tough wires and curcits ?

| we need to remember that our computer is just an electirical machine by generations upgrades it ends to be made with transistors which is (signal or no signal)
| 0,1 so the native language of any machine is 0,1 which is called machine language <<
| but dealing with it is so hard so the solution was assembly language which main idea is to transetate some redable syntax to human to an excutable file as 1s.0s bt assymbler but the main problem was that it still hard and every machine has its own instructions(opcode) which doesnt make since but wait !!
how acually the code runs using assymbly or even the high level prog. ==========>(instruction life cycle)

.........................................................the jouriny of our code starts now ^^
any order or action takes in the computer turns into an instructions put in memory this when we decide to do some operation in this instruction so the cpu statrt the  first_point in cycle 
1-(fetch)
for more declaration الميموري عباره عن بلوكات كل بلوك جواه ورد حسب الos بيكون تقسيمه بلوكاات الميموي 
معني كدا ان الورد ممكن تاخد اكتر من انستركشن؟ الاجابه اه حسب استركشر الرام بتاعي كهردوير
then this instruction stored in (ir) instruction register then (ac) accumelator register if any operations in Alu so we can name this 2-(decode) 
then the excution the result stored in a buffer like (MBR) then transferd throw the bus to memory or i/o(causing intruupt) so this is 3-(excusion)
>>summary instruction life cycle is fetch,decode,excute
>>
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|>>if we come back to the main point of embedded as a technology simply is to convince the microcontroller (small computer) to do specified set of instructions within an archtucture by | |some coding so we git the relation between each hardware and the soft runs into                                                                                                         |
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
the last thing we gonna see why c is the core language for learinig embedded systems 
??
from the relation between the hard and soft the main requirement i need a programing languge can access the addresses of the memory i want to controle the variables but comparing to assymbly c is slower but easir and standrized which a great criteria
note this also the compilation of a c program using any toolchain can run on the same machine (calles native tool chain) 
OR loaded and runs on other archticure like MC ==> AVR,PIC,ARM......

