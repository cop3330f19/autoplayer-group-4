#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Song.h"

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>


class Playlist
{
   private:
    std::vector<Song> lsong;
    int currentsong;
    std::string p_name;
    static char option;
    
   public:
    Playlist();
    Playlist(std::string); 
    
    void addSong(Song& );
    void deleteSong(Song& );
    Playlist intersect(Playlist& );
    bool search(std::vector<Song>, Song& );
    friend Playlist operator+(Playlist& , Playlist& );
    friend Playlist operator+(Playlist& , Song& );
    friend Playlist operator-(Playlist& , Song& );
    friend std::ostream& operator<<(std::ostream& , const Playlist& );
    void play();
    static void mode(char );
    std::vector<Song> getSong();
    void setPName(std::string );
    std::string getPName();
    
    
    
};
#endif
