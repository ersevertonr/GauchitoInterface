#ifndef Reducer_h
#define Reducer_h

class Reducer {
    public:
        Reducer(int value) {
            this->value = value;
        };

        int getValue();

    private:
        int value;
};

#endif Reducer_h
