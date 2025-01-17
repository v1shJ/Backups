#include <iostream>
using namespace std;

#define BUFFER_CAPACITY 5 // The size of the buffer
class Semaphore{
    int count;

    public:
        Semaphore(int firstcount) : count(firstcount){}

        void wait(){
            while (count <= 0)
                ;
            count--;
        }
        void signal(){
            count++;
        }
};

int buffer[BUFFER_CAPACITY];
int in = 0;                  // For producer to add data
int out = 0;                // For consumer to take data
Semaphore emptySlots(BUFFER_CAPACITY); // Initially, all buffer slots are empty
Semaphore full(0);
Semaphore mutex(1);
void producer(int item){
    emptySlots.wait();
    mutex.wait();
    buffer[in] = item;
    cout << "Produced item: " << item << " at position " << in << endl;
    in = (in + 1) % BUFFER_CAPACITY; // Move to the next index in a circular manner
    mutex.signal();
    full.signal();
}

void consumer(){
    full.wait();
    mutex.wait();
    int item = buffer[out];
    cout << "Consumed item: " << item << " from position " << out << endl;
    out = (out + 1) % BUFFER_CAPACITY; // Move to the next index in a circular manner
    mutex.signal();
    emptySlots.signal();
}

int main(){
    int items_to_produce = 10;
    for (int i = 0; i < items_to_produce; ++i){
        producer(i);
        consumer();
    }
    return 0;
}