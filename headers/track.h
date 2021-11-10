#ifndef TRACK_H
#define TRACK_H

#include <iostream>

using namespace std;

class Track{
  public:

    // Constructors -----------------------
    Track();
    Track(string id, string text, int vote, string version, string date);

    // Destructor -------------------------
    ~Track();

    // Get Functions ----------------------
    string getReview_id();
    string getReview_text();
    int getUpvotes();
    string getApp_version();
    string getPosted_date();

    // Set Functions ----------------------
    void setReview_id(string id);
    void setReview_text(string text);
    void setUpvotes(int votes);
    void setApp_version(string version);
    void setPosted_date(string date);

  private:
    string review_id;    // String para armazenar o id do comentário.
    string review_text;  // String para armazenar o comentário.
    int upvotes;         // String para armazenar os votos favoráveis.
    string app_version;  // String para armazenar a versão do app;
    string posted_date;  // String para armazenar a data e hora da postagem.
};

#endif