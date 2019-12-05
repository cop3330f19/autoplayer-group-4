// Song.cpp
// Kristin McGee, Tramia McGee, Jermaine Le Grand
// December 5, 2019
// The purpose of this program to read in songs and playlists from a file and being able to add to a playlist,
// delete from a playlist, add a new playlist, merge a playlist, and intersect a playlist.

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Song.h"
#include "Playlist.h"
#include "StringHelper.h"

using namespace std;

//Constructors
Song::Song( ){
    title = "";
    artist = "";
    album = "";
    length = 0;
    year = 0;
}

Song::Song(string title, string artist, string album, int length, int year){
    set(title, artist, album, length, year);
}

void Song::set(string title, string artist, string album, int length, int year){
    this-> title = title;
    this-> artist = artist;
    this-> album = album;
    this-> length = length;
    this-> year = year;
}

ostream& operator<<(ostream& os, const Song& song){
    os << song.title << " " << song.artist << " " << song.album << " " << song.year << " " << song.length; // output to console
    return os;
}
ofstream& operator<<(ofstream& os, const Song& song){
   os << song.title << "," << song.artist << "," << song.album << "," << song.year << "," << song.length;  //output to file
    return os;
}

fstream& operator>>(fstream& is, Song& song){ //input from file
    string temp;
    
    getline(is, song.title, ',');
    getline(is, song.artist, ',');
    getline(is, song.album, ',');
    getline(is, temp, ',');
    song.year = atoi(temp.c_str());
    getline(is, temp);
    song.length = atoi(temp.c_str());
  
     
    return is;
}

istream& operator>>(istream& is, Song& song){
  
    //is.ignore();
  cout << "Song Details \n";
  cout << "Title: \n";
  getline(is, song.title);
  cout << "Artist: \n";
  getline(is, song.artist);
  cout << "Album: \n";
  getline(is, song.album);
  cout << "Year: \n";
  is >> song.year;
  cout << "Length (in seconds): \n";
  is >> song.length;
    return is;
}

bool operator==(const Song& lhs, const Song& rhs){
    return (lhs.title == rhs.title && lhs.artist == rhs.artist); // compare two song objects for equality
}
