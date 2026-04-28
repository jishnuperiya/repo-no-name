#pragma once
#include<vector>

#include "scale_database.hpp"

//****************************************************************************
namespace  harmony::query{
//****************************************************************************
class visitor
{
public:
  virtual void                     accept(const scale_entry& entry) = 0;
  virtual void                     done() {}
  virtual                          ~visitor() = default;
};

template<class container = std::vector<scale_entry>>
class query_results : public visitor
{
public:
  using iterator = typename container::iterator; // why need typename
  using const_iterator = typename container::const_iterator;

public:
  void                             accept(const scale_entry& entry) override;

                                // container like accessors
  //const std::vector<scale_entry>&  entries()  const;
  bool                             empty()    const;
  std::size_t                      size()     const;

                                 //iterator support
  iterator                         begin();
  iterator                         end();
  const_iterator                   begin()    const;
  const_iterator                   end()      const;

private:
  container         entries_;
};

class query_stream : public visitor
{
public:
                                    query_stream();
  explicit                          query_stream(std::ostream& os);
  void                              accept(const scale_entry& entry) override;
  void                              done()                           override;
private:
  std::ostream* os_; // or reference?
  //const ptr or ref
};

class query_count : public visitor
{
public:

  // Todo - accept(), count(), empty() methods
  
private:
  std::size_t count_ = 0;
};

//****************************************************************************
} // namespace harmony::query
//****************************************************************************