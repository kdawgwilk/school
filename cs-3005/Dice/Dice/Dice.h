#ifndef _DICE_H_
#define _DICE_H_


class Dice {
    private:
        int num;
    public:
        Dice();
        int getValue() const;
        void roll();
};

#endif //_DICE_H_
