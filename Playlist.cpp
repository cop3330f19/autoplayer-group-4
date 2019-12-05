// Playlist.cpp
// Kristin McGee, Tramia McGee, Jermaine Le Grand
// December 5, 2019
// The purpose of this program to read in songs and playlists from a file and being able to add to a playlist,
// delete from a playlist, add a new playlist, merge a playlist, and intersect a playlist.

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Playlist.h"
#include "Song.h"
#include "StringHelper.h"

using namespace std; 

char Playlist::option = 'N'; //Setting mode to N as default

void Playlist::addSong(Song& s1)
{
  lsong.push_back(s1); // Adding a new song to the end of the song vector
}

void Playlist::deleteSong(Song& deletesong){
    
    
    bool valid;
    valid = false;
    for(int i = 0; i < lsong.size(); i++)
    { //Start of for loop
            if(lsong[i] == deletesong){
                valid = true;
               lsong.erase(lsong.begin()+ i);
            }
     }// End the loop
  }

std::vector<Song> Playlist::getSong(){
    return lsong; // Returning a song
}

Playlist Playlist::intersect(Playlist& p2){
    
    Playlist result;
    bool valid;
    vector<Song> temp = p2.getSong();
    
    valid = false;
    
   for(int i = 0; i < lsong.size(); i++){// Start of for loop 
       for(int j = 0; j < temp.size(); j++){
       if(lsong[i] == temp[j] && search(result.getSong(), lsong[i]))
           
         valid = true;  
          
         
           result.addSong(lsong[i]);
        }  
      }// End of for loop
      return result;// Return a playlist
    }

bool Playlist::search(vector<Song> b, Song& g   ) 
{ 
    bool valid;
    
    valid = false;
    for (int i = 0; i < b.size(); i++) 
        if (b[i] == g) 
            valid = true; 
    return valid; 
}

Playlist operator+(Playlist& p1, Playlist& p2)
{
    Playlist merge;
    merge = p1;
    bool valid;
    vector<Song> temp = p2.getSong();
    
    valid = false;
    
   for(int i = 0; i < temp.size(); i++){ // Start of for loop 
           
         valid = true;
    
           merge.addSong(temp[i]);
    }//End of for loop
    return Playlist(merge);
}
Playlist operator+(Playlist& p1, Song& s1)
{
  Playlist a1; //Creating a playlist object
  a1 = p1;
  a1.addSong(s1);
  return Playlist(a1);
   
}

Playlist operator-(Playlist& p1, Song& s1){
    Playlist d1;// Creating a playlist object
    d1 = p1;
    d1.deleteSong(s1);
    return d1;
}

ostream& operator<<(ostream& os, const Playlist& p1 ){
 for(int i=0; i< p1.lsong.size(); i++){
     os << p1.lsong[i]; 
 }  
  return os;
}



void Playlist::play(){
    //cout << option << currentsong << endl;
    if(option == 'N' || option == 'n'){ 
        currentsong++;
          if(currentsong < lsong.size()) // See if the current song is not at the end of the vector.
             cout << lsong[currentsong] << endl; // Print current song using the current index it is at (currentsong)
        else
               
      cout << "There are no more songs to play in the plalist." << endl;
    }
    else if(option == 'R' || option == 'r'){
        cout << lsong[currentsong] << endl; // Printing the same song
    }
    else if(option == 'L' || option == 'l'){
        currentsong++;
        if(currentsong > lsong.size())
            currentsong = 0;
       cout << lsong[currentsong] << endl;
    }
}

void Playlist::mode(char option){
    Playlist::option = option; 
}

void Playlist::setPName(std::string pname){
    p_name = pname;
}
std::string Playlist::getPName(){
    return p_name;
}
Playlist::Playlist(){
    p_name = "";
}
Playlist::Playlist(std::string name){
  setPName(name);
   string play_listname = name + ".playlist";
   play_listname = StringHelper::stou(play_listname);

   fstream in;
	in.open(play_listname.c_str(), ios::in);
    Song s;
    int k =0;
     while(in>>s)  { 

        lsong.push_back(s); // Adding a song to the vector songs.
     }
    in.close();
}

