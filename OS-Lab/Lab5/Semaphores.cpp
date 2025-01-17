#include <iostream>
using namespace std;
class Semaphore{
    private:
        int count;

    public:
        Semaphore(int initial) : count(initial) {}
        void wait(){
            if (count > 0){
                --count;
                cout << "Semaphore acquired, current count: " << count << endl;
            }
            else
                cout << "Semaphore unavailable, waiting..." << "\n";
        }
        
        void signal(){
            ++count;
            cout << "Semaphore released, current count: " << count << "\n";
        }
        int getCount() const{
            return count;
        }
};

int main(){
    Semaphore sem(3);
    sem.wait();
    sem.wait();
    sem.wait();
    sem.wait();
    sem.signal();
    sem.signal();
    sem.wait();
    return 0;
}
