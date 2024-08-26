# 2024-08-26 Mon

Today I worked on adding labs, which currently just consume red science without any effect on the game.

I also started on the research backend which will allow technology progression to actually happen.

I added configuration objects to store data about science: what it unlocks, how long it takes, what the prerequisites are, etc. These are only minimally configured at the moment (no prerequisites, no unlocks stored, and default to 10x science taking 10 seconds each). But it's a start!

Here's a video demo of the game so far. It's got a long, long way to go but it's coming along:

![Video demo](screenshots/2024-08-26-gif.gif)

# 2024-08-25 Sun

Got the crafting screen working, with instant crafts!

![Screenshot](screenshots/2024-08-25.png)

I also added all of the recipe types for starter-game items (i.e. things you don't need to research).

Next, I implemented a timer system to make crafting actually take time. The crafting now occurs as a queue, just like in the original game!

Finally, I added smelting with furnaces.

See the demo in Monday's update!

One problem I encountered today: how to make things like crafting and smelting take time in-game?

How I fixed it: There are two general approaches to time management that I've conceptualised and implemented here. Both rely of the game "tick" system, which is separate from the rendering loop. If all is going well, we get >60 FPS for the rendering, but the ticks are throttled to 60 per second (called "UPS" or updates-per-second in Factorio lingo). Under this system, we can base how long things happen off of the number of ticks. Given this, there are two approaches. I used one for timing smelting, and the other for timing the crafting queue.

The first approach is to track an int containing the number of ticks until an event occurs, and to update this each tick. For example, smelters can track their own smelting progress and decrement an int every tick. This scales up fine for the time being, since decrementing an int is really cheap, and allows the smelters to manage their own progress with checks like "if we run out of fuel, then keep track of the progress, but pause it until we have more fuel". And in fact that's been implemented.

The second approach is a bit more general but perhaps less flexible: an "event" based system. This is coordinated centrally, with some kind of event bus (in Hacktorio, this is a "Timer" class). The timer accepts events, which are queued with a given "number of seconds away" so that the objects queueing them don't have to care about ticks themselves. When the timer adds an event, it calculates which tick number it should fire on (we track a global "what tick are we on" system - basically the game's uptime). Then, each tick we check if there are any "expired" events - that is, events that were due to fire on this tick or a previous tick. For each of them, we fire the event, which consists of running a TimerEvent object containing an arbitrary function. So for crafting, we fire off an event that updates the player's inventory with the item that was created.

This definitely starts to run into problems if the code is multithreaded, but we're operating on a single thread here so it seems fine for now. Time will tell - we need to be able to cancel things in the crafting queue, for example, so maybe we need some way to key events to make them cancelable. Also, the Timer is scanning events in linear time right now - perhaps a priority queue could speed this up, or we could just keep the list sorted (so that binary search can determine which events to fire). This might become important if we're firing a lot of events per tick, but if we are, then the firing is probably going to dominate the time. So in that case, we might be stuck with a linear search anyway, but we can terminate it early if the list is sorted.

# 2024-08-24 Sat

Did a large overhaul of the UI, refactoring into a custom tree-based system with relative positions for each renderable element. This allows the rendering logic to exist in the classes that actually need to be rendered, with each node only concerned with its own rendering.

Also started supporting mouse actions, such as clicking on items to pick them up out of inventory slots.

![Screenshot](screenshots/2024-08-24.png)

Next, I added a basic escape menu, and started working on the crafting panel:

![Screenshot](screenshots/2024-08-24-escape-menu.png)

![Screenshot](screenshots/2024-08-24-crafting-panel.png)

One problem I encountered today: how to represent UI elements so that they can be nested within each other, but also so that they can be rendered with different z-indexes, and also supporting operations like "find any nodes that intersect this point"?

How I fixed it: I've decided to go for a relatively simple approach for now, which we can expand upon later. The key insight was that the spatial index and the scene tree don't need to be the same data structure. I've punted z-index management off to future me, so ignoring that for now makes the problem pretty easy: represent the objects using a tree structure where positions are relative. The relative positions mean that components/subtrees can be reused, just like in React or most other UI frameworks. The spatial index for now just runs brute-force to answer questions like "what did the user click": this is okay because we can keep the same API while making improvements to the indexing (e.g. a quadtree) later, and we won't have to refactor much if any of the calling code. Yay for encapsulation!

# 2024-08-05 Mon

Started rendering a basic grid inventory with item counts. Started factoring out a generalisation of items that will work for both rendering and interactivity - a "scene node" tree.

![Screenshot](screenshots/2024-08-05.png)

One problem I encountered today: the Game class is getting pretty large and unmaintainable.

How I fixed it: started working on splitting up the rendering to make it more generalisable. See tomorrow's update!

# 2024-08-04 Sun

Fixed some issues with pointers. Imported image resources from the real game (behind a gitignore).

![Screenshot](screenshots/2024-08-04.png)

One problem I encountered today: trying to store references to custom objects in classes, but I kept encountering random memory issues like objects flickering.

How I fixed it: I eventually realised this was due to data being allocated on the stack instead of the heap, and to fix it, in most cases I should allocate custom objects on the heap using "MyClass myClass = new MyClass()" instead of just "MyClass myClass". I'm familiar with pointers conceptually, and perhaps this example makes me look a bit naive, but I've spent most of my working life using languages like Kotlin/Java, TypeScript/JavaScript, and Python, so the in-practice issues with memory management aren't something I've had to think about too much (aside from the occasional weak reference in Kt/Java).

I've also heard of unique_ptr and other smart pointers, and maybe I'll give them a try, but for now I want to learn things the "old school" way and solve issues like memory leaks when I run into them - giving myself the real trial by fire treatment.
