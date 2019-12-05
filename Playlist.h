// Playlist.h
// Kristin McGee, Tramia McGee, Jermaine Le Grand
// December 5, 2019
// The purpose of this program to read in songs and playlists from a file and being able to add to a playlist,
// delete from a playlist, add a new playlist, merge a playlist, and intersect a playlist.

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
    std::vector<Song> lsong; // vector of songs
    int currentsong;
    std::string p_name;
    static char option;
    
   public:
    Playlist();
    Playlist(std::string); 
    
    void addSong(Song& );// Adding a song
    void deleteSong(Song& ); // Deleting a song
    Playlist intersect(Playlist& ); // Intersecting two playlist 
    bool search(std::vector<Song>, Song& ); //Searching for song to delete
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
