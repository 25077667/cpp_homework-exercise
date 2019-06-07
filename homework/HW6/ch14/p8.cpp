#include <iostream>
#include <vector>
using namespace std;

class Blog {
   public:
    Blog() {}
    virtual int operateManager()=0;
    void viewPost() {
        for (vector<string>::iterator iter = msg.begin(); iter != msg.end(); iter++)
            cout << iter - msg.begin() + 1 << "\t" << *iter << endl;
    }

   protected:
    vector<string> msg;
};

class BlogOwner : public Blog {
   public:
    BlogOwner() {}
    virtual int operateManager() {
        cout << "Menu options: " << endl
             << "0> Exit" << endl
             << "1> Display all message" << endl
             << "2> Post new message" << endl
             << "3> delete message" << endl;
        int selection;
        cin >> selection;
        cout << endl;
        return selection;
    }
    void postNewMsg() {
        string post;
        cout << "What's on your mind? " << endl;
        while(cin.peek() == '\n')
            cin.ignore();
        getline(cin, post);
        msg.push_back(post);
        cout << "Posted" << endl;
    }
    void deleteMsg() {
        int index;
        cout << "Which message you want ot delete?" << endl;
        cin >> index;
        if (index > msg.size() || index < 0)
            cerr << "index out of range" << endl;
        else {
            msg.erase(msg.begin() + index - 1);
            cout << "Compelete!" << endl;
        }
    }
    vector<string> getMsgVector() const {
        return this->msg;
    }
};

class BlogViewer : public Blog {
   public:
    BlogViewer(const BlogOwner& owner) {
        vector<string> ownerMsg = owner.getMsgVector();
        for (vector<string>::iterator iter = ownerMsg.begin(); iter != ownerMsg.end(); iter++)
            this->msg.push_back(*iter);
    }
    virtual int operateManager() {
        cout << "Menu options: " << endl
             << "0> Exit" << endl
             << "1> Display all message" << endl;
        int selection;
        cin >> selection;
        cout << endl;
        return selection;
    }
};

int main() {
    BlogOwner owner;
    int selection;
    cout << "First enter data as the owner." << endl;
    while (selection = owner.operateManager()) {
        if (selection == 1)
            owner.viewPost();
        else if (selection == 2)
            owner.postNewMsg();
        else if (selection == 3)
            owner.deleteMsg();
        else
            cerr << "input error" << endl;
    }
    BlogViewer guest = owner;
    cout << "Access data as viewer" << endl;
    while(selection = guest.operateManager()){
        if(selection == 1)
            guest.viewPost();
        else
            cerr << "input error" << endl;
    }
    return 0;
}