#pragma once

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "session.h"
#include "trading.h"
#include "execute.h"
#include "accounts.h"

using boost::asio::ip::tcp;

class server
{
public:
    server(boost::asio::io_service& io_service, short port)
        : io_service_(io_service),
        acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
        trading_{accounts_}
    {
        //
        accounts_.Add(12345, 100000);
        accounts_.Add(12345, "samsung", 100);
        accounts_.Add(11111, 200000);
        accounts_.Add(11111, "LG", 300);
        //
        Execute* execute_ = new Execute(io_service, trading_);
        execute_->start();

        session* new_session = new session(io_service_,trading_);
        acceptor_.async_accept(new_session->socket(),
            boost::bind(&server::handle_accept, this, new_session,
                boost::asio::placeholders::error));
    }

    void handle_accept(session* new_session,
        const boost::system::error_code& error)
    {
        if (!error)
        {
            new_session->start();
            new_session = new session(io_service_,trading_);
            acceptor_.async_accept(new_session->socket(),
                boost::bind(&server::handle_accept, this, new_session,
                    boost::asio::placeholders::error));
        }
        else
        {
            delete new_session;
        }
    }

private:
    boost::asio::io_service& io_service_;
    tcp::acceptor acceptor_;
    Trading trading_;
    Accounts accounts_;
};