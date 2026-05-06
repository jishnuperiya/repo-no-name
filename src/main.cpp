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

#include "scale_query_view.hpp"
//****************************************************************************
using namespace harmony::query;
//****************************************************************************
int main()
{

  auto q = cardinality(7) && has_tritone();


  auto results = find(q).collect();
 
  auto first_result = find(q).first();

  find(q).stream(std::cout);


 return 0;
}


//****************************************************************************
