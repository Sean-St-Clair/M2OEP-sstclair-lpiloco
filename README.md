# CS 120 Module 1 Open-Ended Project

For this project, you will design, implement, and use a C++ project.

## Requirements:

- All of your programming files should be in a private GitHub repository in the course organization.
    - Your repository must be named with the convention: M1OEP-netid, where netid is your UVM
      NetID username.
    - The repository should have a .gitignore file, a CMakeLists.txt file, and a README file (see the
      GitHub-with-CLion repo for directions).
- Your README.md file should include:
    - Your name
    - A summary of your program, including a list of Module 1 concepts used
    - Any known bugs at time of submission
    - Future work (how you could expand the program with more time)
    - Citations for any code not written by you or the instructor
    - The grade you think you have earned, based on the grading rubric below, with justification
- All of your files must be pushed to your GitHub repository.
- Create a short video (~5 minutes) giving a brief overview of the program, including a demo.
    - You can record the video on Microsoft Teams or a different program of your choosing. Instructions
      to record in Teams are at the bottom of this spec.
- Submit both the link to your repository and the link to your video.
    - You can upload your video to OneDrive or a different platform of your choosing to obtain a link.

## Main Program:

Your main program should have a clear and complex purpose. It should not be used as a testing file to call methods and
functions. The goals and functionality of your program should inform the development and design of your class(es) and
other concepts. You are highly encouraged to plan and design your main.cpp functionality before writing your other
files.

The program should be interactive and all user input must be validated.

Keep in mind that you will be allowed and encouraged to build on this project for future modules’ open-ended projects,
so putting the time in now to construct a strong foundation will be to your advantage.

## Module 1 Concept Menu:

You can include any number and combination of these C++ concepts from Module 1:

- Class (separated into header and .cpp files, containing at least two fields and at least one method
  that isn’t a constructor, getter, setter, or destructor)
- Overloaded Operator(s) in your class(es)
- Enumerated type(s)
- Struct(s)

All of the above concepts that you design, create, and use in your main program must be clearly listed
in your README.md file.

## Project Brainstorming:

Class concepts:

- Class (very likely)
- Overloaded operators - doable, can do a contest of damage or something(?)
    - Can also do == to check that it's not colliding with self (or something like that)
- Enumerated type - cool, maybe we could do like an entity ID system, like friend or foe
- Structs - hmm going to do some cursory research on this one sec

Maybe the class is called "entity handler" and it contains an entity struct (with some basic values)

- Then the methods actually perform the thing. Like you can link an "update" method into them.
- This architecture seems kinda weird and not actually good for a scalable game tho, so. We'll see. (like it's
  reminiscent of a component-based system but I'm not sure if I wanna dive into that just yet)
- Maybe even just when collisions are resolved there's a "combat info" struct. maybe? like with physics info, ID, damage
  values, etc.

I could also consider foregoing graphics for now, and leaving that for future development. Yeah, I like this as a
text-based thing.

- Perhaps the "struct" is for the room - the description as it is printed out, and optionals for north, east, south,
  west directions. (pointers to other rooms)
- There will be functions for adding rooms onto specific directions, which adds two-directional pointers to both
- Yeah, that could be cool. This is a basic text-based dungeon navigation system (a useful proof-of-concept)
- It asks for input about the new room and where you wanna add it, then at the end it prints it out cuz that'd be
  cool? (like some ascii art of the dungeon layout - a 2D grid of equally-sized cells for now)
  -And the use of overloaded operators is so it detects if you're trying to link 1 room to itself, for instance
  -"Error: cannot place a room to the left of itself!" or something haha.

Ok cool. You could also optionally just create a new room and then link it (hallways / nodes / connections / whatever
are created automatically; otherwise assumed to be a blank wall)

- There could also be a simple "copy" function. So you could be like... "rest room" and scatter copies around the
  dungeon (wait not like a bathroom a room for... rest?? yeah)
- And you could be like copy rest_room rest_room2 (the name has to be unique) and it gives the copies all the values of
  the original but stores it elsewhere in memory (I want to do this instead of just having a shared pointer because I
  may want to then make unique edits to the copy)
- And then you could do link rest_room east rest_room2
    - Oh no it's turning into a little scripting language haha.
    - Honestly input parsing is gonna be the most challenging part of this
    - I should probably do the input validation thing first tbh! Isn't that the AP?
- Also, maybe in the future there could be specifications for room dimensions and special editing of tiles within those
  rooms.
- And eventually even switching to a graphics version of this dungeon generator. Could be cool.

More brainstorming:

- Structs for room display: wall character, floor character, detail character, detail 2 (the last 2 maybe being
  optionals?)
- Dungeon class, for managing rooms and linking them? Rather than a "copy" function. Just add all starting room types,
  then add these to dungeon. Hmmm... Need to remember scope of the project though
- Maybe just a dungeon renderer class, that adds a room of given dimensions alongside the rendering struct to the visual
  map.
- Maybe each room will have a field for its rendering struct
- Rather than room size maybe we should just specify the dungeon coordinates. And then maybe size = small, medium
  large... Hmmm. We need to define the actual input loop more clearly. Room size with specific categories like that
  would make sense for an enum.

## Code Outside Class

- Utilized the input validation from the previous applied project, with some modification

## Future ideas:

- User might want to customize the size of the dungeon
- User may want to see the dungeons actually laid out in the grid in accordance with their linking

## Notes about submission:

- I'm not sure why I ran into an error while recording! I tested it immediately after with no changes, and didn't repeat
  the error.
- This doesn't mean that the function works as expected all of the time, but this is an unfortunate part of developing
  this feature so close to the deadline.