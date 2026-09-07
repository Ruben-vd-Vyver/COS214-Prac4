# Running
## Setting up docker environment
docker build -t taskforge .
docker run --rm -it taskforge bash

## Building and running program
make
./taskforge

## Debugging
gdb ./taskforge
valgrind --leak-check=full --show-leak-kinds=all ./taskforg

# Bug found
*Bug Found During Testing*
While testing the iterator, I found a bug where the program would crash if a unit was deleted while the iterator was still being used. The iterator still had a pointer to the deleted unit, so when it tried to access it again, it was accessing invalid memory. I used GDB to step through the code and check the iterator and unit pointers, which helped me find that the iterator was still pointing to the deleted object. Instead of changing the whole iterator to handle deletions, I decided that units should not be deleted while an iterator is currently being used. The main program already follows this rule, so this should not happen during normal use. I also tested what happens when the rule is broken, which confirmed that the crash was caused by the invalid pointer. <\br>
I ended up deciding on a policy that units should not be deleted while an iterator is being used to traverse them.

# Valgrind output (no memory leaks found)
==9348== Memcheck, a memory error detector
==9348== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9348== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==9348== Command: ./taskforge
==9348== 

----- Roll call (DepthFirstIterator - complete traversal) -----
Incident 47 - Warehouse Fire
Operations Branch
Division A
Strike Team 1
Engine 21
Engine 22
Rescue 5
Medical Branch
Ambulance 9

----- Lifecycle: Engine 21 responds -----
  Engine 21 dispatched.
  Engine 21 confirms en route.
  Engine 21 arrived on scene.
  [INVALID] Engine 21 cannot dispatch while OnScene.

----- Two independent iterators over the same hierarchy -----
Units currently available:
  Engine 22
  Rescue 5
  Ambulance 9
Full roll call, first 3 entries, unaffected by the above:
  Incident 47 - Warehouse Fire
  Operations Branch
  Division A

----- Dynamic decoration: Engine 22 gets hazmat + medical support -----
Engine 22 [MEDIC] [HAZMAT] now carries 6 personnel.
Engine 22 [Staged]: laying hose lines and applying water.
  + medical support: providing on-scene casualty care.
  + hazmat certification: monitoring air quality and decontamination.

----- Re-tasking: Rescue 5 moves from Division A into Strike Team 1 -----
  Rescue 5 dispatched.
  Rescue 5 confirms en route.

----- Full duty performance after all changes -----
Incident 47 - Warehouse Fire
Operations Branch
Division A
Strike Team 1
Engine 21 [OnScene]: laying hose lines and applying water.
Engine 22 [Staged]: laying hose lines and applying water.
  + medical support: providing on-scene casualty care.
  + hazmat certification: monitoring air quality and decontamination.
Rescue 5 [EnRoute]: conducting search and technical rescue.
Medical Branch
Ambulance 9 [Staged]: triaging and transporting patients.

----- Shutdown -----
Incident structure torn down cleanly.
==9348== 
==9348== HEAP SUMMARY:
==9348==     in use at exit: 0 bytes in 0 blocks
==9348==   total heap usage: 58 allocs, 58 frees, 75,857 bytes allocated
==9348== 
==9348== All heap blocks were freed -- no leaks are possible
==9348== 
==9348== For lists of detected and suppressed errors, rerun with: -s
==9348== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)