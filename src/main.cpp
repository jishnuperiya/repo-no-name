//******** Copyright © 2025 Jishnu Periya, Jonathon Bell. All rights reserved.
//*
//*
//*  Version : $Header:$
//*
//*
//*  Purpose :
//*
//*
//****************************************************************************
#include <iostream>                //for cout
#include <ranges>

#include "scale_query.hpp"
#include "scale_visitor.hpp"
#include "scale_query_range.hpp"
#include "scale_database.hpp"
//****************************************************************************
using namespace harmony::query;
//****************************************************************************
int main()
{

 

  scale_filter_view view {cardinality(7) && has_tritone()};

  query_results qr;
  for (const auto& entry : view) // filtering happens only during iteration
  {
    qr.accept(entry);
  }

  query_results qr2;
  visit(cardinality(7) && has_tritone(), qr2);

  std::cout << "finished" << std::endl;




  //auto seven_note_scales = harmony::scale_database::catalog()
  //  | std::views::filter([](const harmony::scale_entry& entry)
  //    {
  //      return entry.pattern.cardinality() == 7;
  //    });



  /*
  
  caller
  │
  ├── composes predicates (scale_query.hpp)
  │
  └── creates scale_filter_view(predicate)
            │
            ├── internally accesses database (hidden)
            │
            └── exposes a range
                      │
                      ├── visitor consumes it
                      ├── exporter consumes it
                      └── find_first consumes it

Database is an implementation detail of scale_filter_view
Everything downstream just sees a range of scale_entry

  */

 return 0;
}


//****************************************************************************
