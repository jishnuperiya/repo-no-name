
/*
QUESTIONS----

1) split the source code to different folders?

harmony/
  
  core/                     # foundational types
    

  query/                    # everything in harmony::query


****************************************

2) query_view : i could have used type erasure
store a predicate pred; 

encapsulation boundaries:

scale_query.cpp          — hidden: walks the database, calls accept()
scale_query.hpp          — declares: find_first(), visit()
query_view (header)      — exposed API: find(), first(), collect(), count()...

query_view is intentionally public.  doesnt touch database directly

/