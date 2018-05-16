#include "Player.h"
#pragma once


class Champion : public Player {
    public:
    const string name() const override;
    const Coordinate play(const Board& board) override;
}
