#include "main.h"
#include "addData.h"
#include "connection.h"
#include <Wt/Dbo/backend/Postgres.h>
#include <memory>
#include <utility>


int main()
{
    try
    {
        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);

        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));

        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Shop>("shop");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");
        session.createTables();
        addData(session);

        std::string name;
        std::cout << "Enter publisher name: ";
        std::getline(std::cin >> std::ws, name);

        Wt::Dbo::Transaction transactionFind{ session };

        Wt::Dbo::ptr<Publisher> publisher = session.find<Publisher>().where("name = ?").bind(name);

        if (publisher)
        {
            std::cout << "Publisher: " << publisher->name << '\n';
            for (const auto& book : publisher->books)
            {
                for (const auto& stock : book->stocks)
                {
                    std::cout << stock->shop->name << '\n';
                }
            }
        }
        else
        {
            std::cout << "Publisher not found!\n";
        }

        transactionFind.commit();

    }
    catch (const Wt::Dbo::Exception& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
	return EXIT_SUCCESS;
}
