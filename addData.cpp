#include "addData.h"


void addData(Wt::Dbo::Session& session)
{
    //add Publisher
    Wt::Dbo::Transaction transactionPub{ session };

    //1
    std::unique_ptr<Publisher> publisher1{ new Publisher() };
    publisher1->name = "HarperCollins";

    Wt::Dbo::ptr<Publisher> pub1Ptr = session.add(std::move(publisher1));

    //2
    std::unique_ptr<Publisher> publisher2{ new Publisher() };
    publisher2->name = "Bloomsbury Publishing";

    Wt::Dbo::ptr<Publisher> pub2Ptr = session.add(std::move(publisher2));

    //3
    std::unique_ptr<Publisher> publisher3{ new Publisher() };
    publisher3->name = "Penguin Random House";

    Wt::Dbo::ptr<Publisher> pub3Ptr = session.add(std::move(publisher3));

    transactionPub.commit();

    //------------------------------------------------------------------------------------------------------//
    //add Book
    Wt::Dbo::Transaction transactionBook{ session };

    //1 - 1
    std::unique_ptr<Book> book1{ new Book() };
    book1->publisher = pub1Ptr;
    book1->title = "Agent of Joy";

    Wt::Dbo::ptr<Book> book1Ptr = session.add(std::move(book1));

    //1 - 2
    std::unique_ptr<Book> book2{ new Book() };
    book2->publisher = pub1Ptr;
    book2->title = "Admiring Dreams";

    Wt::Dbo::ptr<Book> book2Ptr = session.add(std::move(book2));

    //2 - 1
    std::unique_ptr<Book> book3{ new Book() };
    book3->publisher = pub2Ptr;
    book3->title = "Amusing Dreams";

    Wt::Dbo::ptr<Book> book3Ptr = session.add(std::move(book3));

    //3 - 1
    std::unique_ptr<Book> book4{ new Book() };
    book4->publisher = pub3Ptr;
    book4->title = "Avoiding the End";

    Wt::Dbo::ptr<Book> book4Ptr = session.add(std::move(book4));

    //3 - 2
    std::unique_ptr<Book> book5{ new Book() };
    book5->publisher = pub3Ptr;
    book5->title = "Bandit of The Frontline";

    Wt::Dbo::ptr<Book> book5Ptr = session.add(std::move(book5));

    //3 - 3
    std::unique_ptr<Book> book6{ new Book() };
    book6->publisher = pub3Ptr;
    book6->title = "Blacksmith Without Fear";

    Wt::Dbo::ptr<Book> book6Ptr = session.add(std::move(book6));

    transactionBook.commit();

    //------------------------------------------------------------------------------------------------------//
    //add shops
    Wt::Dbo::Transaction transactionShop{ session };
    std::unique_ptr<Shop> shop1{ new Shop() };
    shop1->name = "The Book Basement";

    Wt::Dbo::ptr<Shop> shop1Ptr = session.add(std::move(shop1));

    //

    std::unique_ptr<Shop> shop2{ new Shop() };
    shop2->name = "Books Portfolio";

    Wt::Dbo::ptr<Shop> shop2Ptr = session.add(std::move(shop2));

    //

    std::unique_ptr<Shop> shop3{ new Shop() };
    shop3->name = "The Book Train";

    Wt::Dbo::ptr<Shop> shop3Ptr = session.add(std::move(shop3));

    //

    std::unique_ptr<Shop> shop4{ new Shop() };
    shop4->name = "Peepers Books";

    Wt::Dbo::ptr<Shop> shop4Ptr = session.add(std::move(shop4));

    //

    std::unique_ptr<Shop> shop5{ new Shop() };
    shop5->name = "We Love Books!";

    Wt::Dbo::ptr<Shop> shop5Ptr = session.add(std::move(shop5));

    //

    std::unique_ptr<Shop> shop6{ new Shop() };
    shop6->name = "The Literary Hub";

    Wt::Dbo::ptr<Shop> shop6Ptr = session.add(std::move(shop6));
    transactionShop.commit();

    //------------------------------------------------------------------------------------------------------//
    //add stock
    Wt::Dbo::Transaction transactionStock{ session };

    //1
    std::unique_ptr<Stock> stock1{ new Stock() };
    stock1->book = book6Ptr;
    stock1->shop = shop1Ptr;
    stock1->count = 3;

    Wt::Dbo::ptr<Stock> stock1Ptr = session.add(std::move(stock1));

    //2
    std::unique_ptr<Stock> stock2{ new Stock() };
    stock2->book = book6Ptr;
    stock2->shop = shop3Ptr;
    stock2->count = 6;

    Wt::Dbo::ptr<Stock> stock2Ptr = session.add(std::move(stock2));

    //3
    std::unique_ptr<Stock> stock3{ new Stock() };
    stock3->book = book1Ptr;
    stock3->shop = shop3Ptr;
    stock3->count = 9;

    Wt::Dbo::ptr<Stock> stock3Ptr = session.add(std::move(stock3));

    //4
    std::unique_ptr<Stock> stock4{ new Stock() };
    stock4->book = book2Ptr;
    stock4->shop = shop4Ptr;
    stock4->count = 1;

    Wt::Dbo::ptr<Stock> stock4Ptr = session.add(std::move(stock4));

    //5
    std::unique_ptr<Stock> stock5{ new Stock() };
    stock5->book = book3Ptr;
    stock5->shop = shop5Ptr;
    stock5->count = 4;

    Wt::Dbo::ptr<Stock> stock5Ptr = session.add(std::move(stock5));

    //6
    std::unique_ptr<Stock> stock6{ new Stock() };
    stock6->book = book2Ptr;
    stock6->shop = shop6Ptr;
    stock6->count = 7;

    Wt::Dbo::ptr<Stock> stock6Ptr = session.add(std::move(stock6));

    //7
    std::unique_ptr<Stock> stock7{ new Stock() };
    stock7->book = book4Ptr;
    stock7->shop = shop2Ptr;
    stock7->count = 6;

    Wt::Dbo::ptr<Stock> stock7Ptr = session.add(std::move(stock7));

    //8
    std::unique_ptr<Stock> stock8{ new Stock() };
    stock8->book = book5Ptr;
    stock8->shop = shop4Ptr;
    stock8->count = 8;

    Wt::Dbo::ptr<Stock> stock8Ptr = session.add(std::move(stock8));

    transactionStock.commit();
    //------------------------------------------------------------------------------------------------------//
}