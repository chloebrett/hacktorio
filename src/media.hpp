#pragma once

/**
 * Interface for interacting with the media library (SFML) and the OS. This abstracts away any operations that involve
 * talking to the hardware or OS - including displaying things on screen, playing sounds and receiving keyboard and
 * mouse input.
 * 
 * In theory, this should make the game more portable.
 */

class Media {
    public:
    void init();
};
