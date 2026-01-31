#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}  // virtual destructor for interface
};
    
// Abstract Observable interface: a YouTube channel interface
class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};
class Channel:public IChannel{
    private:
    vector<ISubscriber*>subscribers;
    string name;
    string latestVideo;
    public:
     Channel(const string& name) {
        this->name = name;
    }
    void subscribe(ISubscriber* subscriber) override{
        if(find(subscribers.begin(),subscribers.end(),subscriber)==subscribers.end()){
            subscribers.push_back(subscriber);
        }
    }
    void unsubscribe(ISubscriber * subscriber){
         auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }
    void notifySubscribers() override {
        for (ISubscriber* sub : subscribers) {
            sub->update();
        }
    }

    // Upload a new video and notify all subscribers
    void uploadVideo(const string& title) {
        latestVideo = title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]\n";
        notifySubscribers();
    }

    // Read video data
    string getVideoData() {
        return "\nCheckout our new Video : " + latestVideo + "\n";
    }

};
class Subscriber:public ISubscriber{
    private:
    string name;
    Channel* channel;
    public:
    Subscriber(const string& name, Channel* channel) {
        this->name = name;
        this->channel = channel;
    }

    // Called by Channel; prints notification message
    void update() override {
        cout << "Hey " << name << "," << this->channel->getVideoData();
    }
};
int main(){
    Channel* travelwithAk=new Channel("Travel with Ak");

    Subscriber* s1=new Subscriber("sonu",travelwithAk);
    Subscriber* s2=new Subscriber("raju",travelwithAk);
    travelwithAk->subscribe(s1);
    travelwithAk->subscribe(s2);

    travelwithAk->uploadVideo("russia ice vlog");

    travelwithAk->unsubscribe(s2);
    
    travelwithAk->uploadVideo("First impression of damascus");
    return 0;

}