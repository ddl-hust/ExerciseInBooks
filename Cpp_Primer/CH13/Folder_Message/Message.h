// 自定义message
#include <string>
#include <set>
#include <iostream>
using std::set;
using std::string;

class Folder;
class Message
{
friend class Folder;
private:
    string contents;
    set<Folder *> folders; //消息出现的文件夹集合
    //utility fuction 拷贝成员都需要用到    
    void add_to_folders(const Message &m)
    {
        for(auto c:m.folders){c.addMsg(this);}
    }
    void remove_from_folders()
    {
        for(auto c:folders) c.remMsg(this);
    }

public:
    Message(string s = "") : contents(s) {}
    Message(const Message &rval):contents(rval.contents),folders(rval.folders)
    {
        add_to_folders(rval);
    }
    ~Message(){remove_from_folders();}

    Message &operator=(const Message &rval)
    {
        remove_from_folders(); //注意remove与add顺序对自赋值影响
        contents=rval.contents;
        folders=rval.folders;
        add_to_folders(rval);
        return *this;
    }
    //从给定文件夹添加或删除
    void save(Folder &);
    void remove(Folder &);

    //insert or remove agiven Folder* into folders
    void addFolder(Folder* f){ folders.insert(f);}
    void remFolder(Folder* f){folders.erase(f);}
};
class Folder{
private:
    set<Message*> msgs;

public:

    void remMsg(Message* m) {msgs.erase(m);}
    void addMsg(Message* m){msgs.insert(m);}

};
void Message::save(Folder& f){
    folders.insert(&f);
    f.addMag(this);
}
void Message::remove(Folder& f){
    folders.erase(&f);
    f.remMsg(this);
}
