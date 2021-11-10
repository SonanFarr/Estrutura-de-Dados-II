#include <iostream>
#include <fstream>
#include "../headers/track.h"

using namespace std;

// Constructors --------------------------------------------------------------
Track::Track(){

}

Track::Track(string id, string text, int vote, string version, string date){
    review_id = id;
    review_text = text;  
    upvotes = vote;         
    app_version = version;  
    posted_date = date;
}

// Destructors ---------------------------------------------------------------
Track::~Track(){

}

// Get Functions -------------------------------------------------------------
string Track::getReview_id(){
    return review_id;
}

string Track::getReview_text(){
    return review_text;
}

string Track::getApp_version(){
    return app_version;
}

string Track::getPosted_date(){
    return posted_date;
}

int Track::getUpvotes(){
    return upvotes;
}

// Set Functions -------------------------------------------------------------
void Track::setReview_id(string id){
    review_id = id;
}

void Track::setReview_text(string text){
    review_text = text;
}

void Track::setUpvotes(int votes){
    upvotes = votes;
}

void Track::setApp_version(string version){
    app_version = version;
}

void Track::setPosted_date(string date){
    posted_date = date;
}

