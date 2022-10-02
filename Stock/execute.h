#pragma once

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "trading.h"


class Execute
{
public:
    Execute(boost::asio::io_service& io_service,Trading& trading_):
        timer{ io_service,std::chrono::steady_clock::now() + std::chrono::seconds(1) }, trading_{ trading_ }
    {

    }

    void start()
    {
        timer.async_wait(boost::bind(&Execute::TimerHandler,this,boost::asio::placeholders::error));
    }

    void TimerHandler(const boost::system::error_code& error)
    {
        if (!error)
        {
            //printf("timer handler executed!\n");
            trading_.OrderExecute();
            trading_.Print();
            timer.expires_at(std::chrono::steady_clock::now() + std::chrono::seconds(1));
            timer.async_wait(boost::bind(&Execute::TimerHandler, this, boost::asio::placeholders::error));
        }
        else
        {
            delete this;
        }
    }

private:
    boost::asio::steady_timer timer;
    Trading& trading_;
   
};

