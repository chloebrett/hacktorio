# hacktorio
Factorio clone written in C++ and SFML

This is a project I've been working on in my spare time purely for learning purposes. Some goals of the project:

* Implement some of the interesting core mechanics of the game Factorio.
* Do it from scratch as much as possible. Don't use an engine - just a basic library like SFML, and even then only really use it as a pixel/sprite buffer. Try to implement core systems like the game loop management, dependency injection, timing, and even composable UI by myself to learn how they work.
* Don't worry about keeping the code super well factored to start with. It's okay if business logic and more general things get a bit tangled together. Don't prematurely optimize this into a game with a completely factored-out engine.
* Make it work, then refactor it to make it clean, then add the next feature and continue.
* Work on the bits that seem fun to me!
* Keep a [devlog](https://github.com/chloebrett/hacktorio/blob/main/devlog.md).
* Be okay with publishing something unpolished! Attaching my name to this is kind of scary since I haven't really worked on C++ in a professional context before, and I'm fairly certain I'm doing a lot of things poorly, or at least differently to how an experienced team would handle them. But that's kind of the point!
* Use this as an excuse to play around with interesting things in a low stakes context. Try smart pointers, Copilot, various build systems, code coverage, valgrind, what have you.
* Interweave learning - for example by watching [Yan Chernikov](https://www.youtube.com/@TheCherno)'s videos, and reading books - with a real project where I get to apply what I've learned.

I don't intend for others to really run this - if you do, you'll need your own copy of Factorio for the assets, and then you'll need to copy them over to the game folder - not to mention installing SFML yourself. This really is a "for me" learning project, and the repo was private until recently :)

Since you asked, here's a screencap:

![Video demo](screenshots/2024-08-26-gif.gif)

Here are some of the features I've implemented, or partially implemented:

* Basic UIs for the inventory, smelting/lab/other entity screens, and pause menu
* Chests
* Smelting
* Labs
* Mining ores by hand
* Mining drills that automatically mine ores
* Crafting (with a queue!) - in fact all non-researched recipes are present and functional.
* Registration of research recipes
* Belts (WIP)

Some obvious things I'd want to add next:

* Displaying the research queue and letting the user choose the research
* Inserters
* Belts
* Assembling machines
* Moving around the map (currently the view is the entire map)
* Better depth buffering (render order is pretty random at the moment)
* DAG-based automatic transient crafting (I love this feature in the real game).
* Water
* Power

I'm not too interested in the combat part of the game, since you can do entire play throughs without it - although things like the enemy pathfinding AI are kind of interesting.

Some other considerations and thoughts:

* This is all very OOP, which isn't really optimal for a mangement simulation game. That's not a concern right now, but I've seen the dev team talk about things like [optimizing the way items are processed on belts](https://www.factorio.com/blog/post/fff-176), by not actually allocating objects for them.
* I've used lambdas in some places, dynamic dispatch in others. unique_ptr in some places, raw pointers elsewhere... the whole thing looks like it was written by someone learning C++ for what is realistically the first time, which is what it is!
* Fix up the codebase to allocate memory a bit more consistently. Like I said above, the pointer situation is a bit messy.
* I'm reasonably happy with the dependecy injection setup I've got going. I think it's made the system a lot more maintainable.
* Why is refactoring C++ so slow! I'm using VSCode with various debug extensions, and even so I'm finding that what should be simple changes (fixing imports for example), needs to be done by hand. CLion costs money. Is there a better IDE for this?
* Copilot is pretty good at filling out lists of items, etc. I give it one example, and especially if there's an enum to read from it is pretty good at guessing the rest. I've used this for item types, ore types, recipes, and so on.
