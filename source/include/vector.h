#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <exception>    // std::out_of_range
#include <iostream>     // std::cout, std::endl
#include <memory>       // std::unique_ptr
#include <iterator>     // std::advance, std::begin(), std::end(), std::ostream_iterator
#include <algorithm>    // std::copy, std::equal, std::fill
#include <initializer_list> // std::initializer_list
#include <cassert>      // assert()
#include <limits>       // std::numeric_limits<T>
#include <cstddef>      // std::size_t
#include <cmath>        // pow function
#include <string.h>
/// Sequence container namespace.
namespace sc {
/// Implements tha infrastrcture to support a bidirectional iterator.
    template < class T >
    class MyForwardIterator {
        public:
            typedef MyForwardIterator iterator;   //!< Alias to iterator.
            // Below we have the iterator_traits common interface
            typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
            typedef T value_type;           //!< Value type the iterator points to.
            typedef T* pointer;             //!< Pointer to the value type.
            typedef T& reference;           //!< Reference to the value type.
            typedef const T& const_reference;           //!< Reference to the value type.
            typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.

            /*! Create an iterator around a raw pointer.
             * \param pt_ raw pointer to the container.
             */
            MyForwardIterator( pointer pt=nullptr ) : m_ptr( pt ) { /* empty */ }

            /// Access the content the iterator points to.
            reference operator*( void ) const {  assert( m_ptr != nullptr ); return *m_ptr; }

            /// Overloaded `->` operator.
            pointer operator->( void ) const {   assert( m_ptr != nullptr ); return m_ptr; }

            /// Assignment operator.
            iterator & operator=( const iterator & ) = default;
            /// Copy constructor.
            MyForwardIterator( const iterator & ) = default;

            /// Pre-increment operator.
            iterator operator++( void ){
                // TODO
                m_ptr++;
                return *this;
            }

            /// Post-increment operator.
            iterator operator++( int ){
                // TODO
                iterator dummy = m_ptr;
                m_ptr++;
                return dummy;
            }

            /// Pre-decrement operator.
            iterator operator--( void ){
                // TODO
                m_ptr--;
                return *this;
            }
            /// Post-decrement operator.
            iterator operator--( int ){
                // TODO
                 iterator dummy = m_ptr--;
                return dummy;
            }
            /// offset increment operator
            iterator& operator+=(difference_type offset){
                iterator &it{*this};
                it.m_ptr+=offset;
                // TODO
                return it;
            }
            /// offset decrement operator
            iterator& operator-=(difference_type offset){
                iterator &it{*this};
                it.m_ptr-=offset;
                // TODO
                return it;
            }
            /// Lesser than operator
            friend bool operator<(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr < itb.m_ptr;
            }
            ///Greater than operator
            friend bool operator>(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr > itb.m_ptr;
            }
            ///Greater than or equal operator
            friend bool operator>=(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr >= itb.m_ptr;
            }
            /// Lesser than or equal operator
            friend bool operator<=(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr <= itb.m_ptr;
            }
            /// Sum operator + it
            friend iterator operator+( difference_type offset, iterator it ){
                // TODO
                iterator dummy = offset + it.m_ptr;
                return dummy;
            }
            /// Sum operator it +
            friend iterator operator+( iterator it, difference_type offset ){
                // TODO
                iterator dummy = it.m_ptr + offset;
                return dummy;
            }
            /// Subtraction operator it -
            friend iterator operator-( iterator it, difference_type offset ){
                // TODO
                iterator dummy = it.m_ptr - offset;
                return dummy;
            }            
            /// Subtraction operator - it 
            friend iterator operator-(difference_type offset , iterator it){
                // TODO
                iterator dummy = offset - it.m_ptr;
                return dummy;
            }

            /// Equality operator.
            bool operator==( const iterator & rhs_ ) const {
                // TODO
                return m_ptr == rhs_.m_ptr;
            }

            /// Not equality operator.
            bool operator!=( const iterator & rhs_ ) const {
                // TODO
                return m_ptr != rhs_.m_ptr;
            }

            /// Returns the difference between two iterators.
            difference_type operator-( const iterator & rhs_ ) const {
                // TODO
                return m_ptr - rhs_.m_ptr;
            }

            /// Stream extractor operator.
            friend std::ostream& operator<<( std::ostream& os_, const MyForwardIterator &p_ )
            {
                os_ << "[@ " << p_.m_ptr  << ": " << *p_.m_ptr << " ]" ;
                return os_;
            }

        private:
            pointer m_ptr; //!< The raw pointer.
    };

    template < class T >
    class MyForwardConstIterator {
        public:
            typedef MyForwardConstIterator iterator;   //!< Alias to iterator.
            // Below we have the iterator_traits common interface
            typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
            typedef T value_type;           //!< Value type the iterator points to.
            typedef const T* pointer;             //!< Pointer to the value type.
            typedef T& reference;           //!< Reference to the value type.
            typedef const T& const_reference;           //!< Reference to the value type.
            typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.

            /*! Create an iterator around a raw pointer.
             * \param pt_ raw pointer to the container.
             */
            MyForwardConstIterator( pointer pt=nullptr ) : m_ptr( pt ) { /* empty */ }

            /// Access the content the iterator points to.
            reference operator*( void ) const {  assert( m_ptr != nullptr ); return *m_ptr; }

            /// Overloaded `->` operator.
            pointer operator->( void ) const {   assert( m_ptr != nullptr ); return m_ptr; }

            /// Assignment operator.
            iterator & operator=( const iterator & ) = default;
            /// Copy constructor.
            MyForwardConstIterator( const iterator & ) = default;

             /// Post-increment operator.
            iterator operator++( int ){
                // TODO
                iterator dummy = m_ptr;
                m_ptr++;
                return dummy;
            }

            /// Pre-decrement operator.
            iterator operator--( void ){
                // TODO
                m_ptr--;
                return *this;
            }
            /// Post-decrement operator.
            iterator operator--( int ){
                // TODO
                 iterator dummy = m_ptr--;
                return dummy;
            }
            /// offset increment operator
            iterator& operator+=(difference_type offset){
                iterator &it{*this};
                it.m_ptr+=offset;
                // TODO
                return it;
            }
            /// offset decrement operator
            iterator& operator-=(difference_type offset){
                iterator &it{*this};
                it.m_ptr-=offset;
                // TODO
                return it;
            }
            /// Lesser than operator
            friend bool operator<(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr < itb.m_ptr;
            }
            ///Greater than operator
            friend bool operator>(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr > itb.m_ptr;
            }
            ///Greater than or equal operator
            friend bool operator>=(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr >= itb.m_ptr;
            }
            /// Lesser than or equal operator
            friend bool operator<=(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr <= itb.m_ptr;
            }
            /// Sum operator + it
            friend iterator operator+( difference_type offset, iterator it ){
                // TODO
                iterator dummy = offset + it.m_ptr;
                return dummy;
            }
            /// Sum operator it +
            friend iterator operator+( iterator it, difference_type offset ){
                // TODO
                iterator dummy = it.m_ptr + offset;
                return dummy;
            }
            /// Subtraction operator it -
            friend iterator operator-( iterator it, difference_type offset ){
                // TODO
                iterator dummy = it.m_ptr - offset;
                return dummy;
            }            
            /// Subtraction operator - it 
            friend iterator operator-(difference_type offset , iterator it){
                // TODO
                iterator dummy = offset - it.m_ptr;
                return dummy;
            }

            /// Equality operator.
            bool operator==( const iterator & rhs_ ) const {
                // TODO
                return m_ptr == rhs_.m_ptr;
            }

            /// Not equality operator.
            bool operator!=( const iterator & rhs_ ) const {
                // TODO
                return m_ptr != rhs_.m_ptr;
            }

            /// Returns the difference between two iterators.
            difference_type operator-( const iterator & rhs_ ) const {
                // TODO
                return m_ptr - rhs_.m_ptr;
            }

            /// Stream extractor operator.
            friend std::ostream& operator<<( std::ostream& os_, const MyForwardConstIterator &p_ )
            {
                os_ << "[@ " << p_.m_ptr  << ": " << *p_.m_ptr << " ]" ;
                return os_;
            }

        private:
            pointer m_ptr; //!< The raw pointer.
    };

    template < typename T >
    class vector
    {
            
        //=== Aliases
        public:
            using size_type = unsigned long; //!< The size type.
            using value_type = T;            //!< The value type.
            using pointer = value_type*;     //!< Pointer to a value stored in the container.
            using reference = value_type&;   //!< Reference to a value stored in the container.
            using const_reference = const value_type&; //!< Const reference to a value stored in the container.

            using iterator = MyForwardIterator< value_type >; //!< The iterator, instantiated from a template class.
            using const_iterator = MyForwardIterator< const value_type >; //!< The const_iterator, instantiated from a template class.
        private:
            size_type v_capacity;   //!< Storage capacity.
            size_type v_end;        //!< How many elements currently stored in the array.
            pointer v_data;         //!< Stores the data.
            size_type s{0};

            // Function that increases the size of the vector in a pow of 2 + an especified amount;
            void increase_size( size_type amount = 0){
                v_capacity = amount;
                pointer new_data = new T[v_capacity];
                std::copy(this->begin(),this->end(),new_data);
                this->~vector();
                v_data = new_data;
            }
            // Function that tests if the vector is full
            bool full( void ) const{
                return v_end == v_capacity;
            }
            
        public:
            //=== [I] SPECIAL MEMBERS (6 OF THEM)

            // Initialize the vector empty with or without a especific capacity
            explicit vector( size_type cp = 0 ){ 
                v_data = new T[cp];
                v_capacity = cp;
                v_end = cp; 
            }
            //Destrutor do Vector
            virtual ~vector( void ){
                 if (v_data != nullptr) delete[] v_data;
            }
            // Initialize the vector from another vector
            vector(const vector & target){
                v_capacity = target.capacity();
                v_data = new T[v_capacity];
                v_end = target.size();  // Vector Starts Full
                // Copy the elements from the target into the Vector
                std::copy(target.cbegin(),target.cend(), v_data);
            }
            // Initialize the vector from a initializer list
            vector( std::initializer_list<T> target){
                v_capacity = target.size();
                v_data = new T[v_capacity];
                v_end = target.size();  // Vector Starts Full
                // Copy the elements from the target into the Vector
                std::copy(target.begin(),target.end(), v_data);
            }
            // Initialize the vector from two iterators
            template < typename InputItr >
            vector( InputItr begin, InputItr end){
                v_capacity = end - begin;
                v_data = new T[v_capacity];
                v_end = v_capacity;
                std::copy(begin,end, v_data);
            };

            // Initialize the vector form the "=" operator using another vector
            vector & operator=( const vector & target){
                v_capacity = target.capacity();
                v_data = new T[v_capacity];
                v_end = target.size();  // Vector Starts Full
                // Copy the elements from the target into the Vector.
                std::copy(target.cbegin(),target.cend(), v_data);
            }


            //=== [II] ITERATORS
            
            // Returns iterator to the first element of the vector
            iterator begin( void ){
                return iterator(&v_data[0]);
            }
            // Returns iterator to the end of the vector
            iterator end( void ){
                return iterator(&v_data[v_end]);
            }
            // Returns a constant iterator to the first element of the vector
            const_iterator cbegin( void ) const{
                return const_iterator(&v_data[0]);
            }
            // Returns a constant iterator to the end of the vector
            const_iterator cend( void ) const{
                return const_iterator(&v_data[v_end]);
            }

            // [III] Capacity

            // Return the amount of elements stored in the vector
            size_type size( void ) const{
                return v_end;
            }
            // Return the amount of allocated space in the vector
            size_type capacity( void ) const{
                return v_capacity;
            }
            // Checks if the vector is empty
            bool empty( void ) const{
                return v_end == 0;
            }

            // [IV] Modifiers

            //Clear all content inside the vector
            void clear(void){
                for(size_type i{0};i<v_end; ++i)
                    v_data[i].~T();
                v_end = 0;
            }

            // Inserts a value in the first position of the vector
            void push_front( const_reference value){
                if (full()) {
                    size_type new_capacity{v_capacity};
                    if (v_capacity == 0) new_capacity++;
                    else new_capacity *= 2;
                    reserve(new_capacity);
                }
                for (size_type i{v_end}; i > 0; --i) v_data[i] = v_data[i-1];
                v_data[0] = value;
            }
            // Inserts a value in the last position of the vector
            void push_back( const_reference value){
                 if (full()) {
                    size_type new_capacity{v_capacity};
                    if (v_capacity == 0) new_capacity++;
                    else new_capacity *= 2;
                    reserve(new_capacity);
                }
                v_data[v_end++] = value;
            }
            // Erases a value in the last position of the vector
            void pop_back( void ){
                v_data[v_end-1].~T();
                v_end--;
            }
            // Erases a value in the first position of the vector
            void pop_front( void ){
                v_end--;
                for (size_type i{0}; i < v_end; i++) v_data[i] = v_data[i+1];
                v_data[v_end].~T();
                
            }

            // Inserts a Value in a determined iterator of the vector
            iterator insert( iterator pos_ , const_reference value_ ){
                size_type position = pos_ - this->begin();
                reserve(v_end+1);                
                if (position < v_end){
                    for (size_type i{v_end}; i > position; i--) v_data[i] = v_data[i - 1];
                    v_end+=1;
                }
                else {                    
                    for (size_type i{v_end}; i < position; i++) v_data[i] = value_type();
                    v_end = position+1;
                }                     
                v_data[position] = value_;                    
                return iterator(&v_data[position]);  
            };
            // Inserts a Value in a determined constant iterator of the vector
            iterator insert( const_iterator pos_ , const_reference value_ ){
                size_type position = pos_ - this->begin();
                reserve(v_end+1);                   
                if (position < v_end){
                    for (size_type i{v_end}; i > position; i--) v_data[i] = v_data[i - 1];
                    v_end+=1;
                }
                else {                    
                    for (size_type i{v_end}; i < position; i++) v_data[i] = value_type();
                    v_end = position+1;
                }                     
                v_data[position] = value_;                    
                return iterator(&v_data[position]);  
            }

            // Inserts a range of values of the first iterator to the last iterator before the determined iterador of the vector
            template < typename InputItr >
            iterator insert( iterator pos_ , InputItr first_, InputItr last_ ){
                size_type count = (last_- first_);
                size_type position{pos_ - this->begin()};
                reserve(v_end+count);               
                if (position < v_end){
                    for (size_type i{v_end-1}; i >= position; i--) {                        
                        v_data[i+count] = v_data[i];
                        if (i == 0) {
                            break;
                        }
                    }
                    v_end+=count;
                }
                else{
                    for (size_type i{v_end}; i < (position+count); i++) v_data[i] = value_type();
                    v_end = position+count;
                }

                size_type aux{0};
                for (auto i{position}; i < (position+count);i++) { 
                    v_data[i] = *(first_ + aux);
                    aux++;
                }
                return iterator(&v_data[position]);                                
            }
            
            // Inserts a constant range of values of the first iterator to the last iterator before the determined constant iterador of the vector
            template < typename InputItr >
            iterator insert( const_iterator pos_ , InputItr first_, InputItr last_ ){
                size_type count = (last_- first_);
                size_type position{pos_ - this->begin()};
                reserve(v_end+count);               
                if (position < v_end){
                    for (size_type i{v_end-1}; i >= position; i--) {                        
                        v_data[i+count] = v_data[i];
                        if (i == 0) {
                            break;
                        }
                    }
                    v_end+=count;
                }
                else{
                    for (size_type i{v_end}; i < (position+count); i++) v_data[i] = value_type();
                    v_end = position+count;
                }

                size_type aux{0};
                for (auto i{position}; i < (position+count);i++) { 
                    v_data[i] = *(first_ + aux);
                    aux++;
                }
                return iterator(&v_data[position]);          
            }

            // Inserts a initializer list before the determined iterador of the vector
            iterator insert( iterator pos_, const std::initializer_list< value_type >& ilist_ ){
                size_type count = (ilist_.size());
                size_type position{pos_ - this->begin()};
                reserve(v_end+count);               
                if (position < v_end){
                    for (size_type i{v_end-1}; i >= position; i--) {                        
                        v_data[i+count] = v_data[i];
                        if (i == 0) {
                            break;
                        }
                    }
                    v_end+=count;
                }
                else{
                    for (size_type i{v_end}; i < (position+count); i++) v_data[i] = value_type();
                    v_end = position+count;
                }

                size_type aux{0};
                for (auto i{position}; i < (position+count);i++) { 
                    v_data[i] = *(ilist_.begin() + aux);
                    aux++;
                }
                return iterator(&v_data[position]); 
            }

            // Inserts a initializer list before the determined constant iterador of the vector
            iterator insert( const_iterator pos_, const std::initializer_list< value_type >& ilist_ ){
                size_type count = (ilist_.size());
                size_type position{pos_ - this->begin()};
                reserve(v_end+count);               
                if (position < v_end){
                    for (size_type i{v_end-1}; i >= position; i--) {                        
                        v_data[i+count] = v_data[i];
                        if (i == 0) {
                            break;
                        }
                    }
                    v_end+=count;
                }
                else{
                    for (size_type i{v_end}; i < (position+count); i++) v_data[i] = value_type();
                    v_end = position+count;
                }

                size_type aux{0};
                for (auto i{position}; i < (position+count);i++) { 
                    v_data[i] = *(ilist_.begin() + aux);
                    aux++;
                }
                return iterator(&v_data[position]); 
            }

            // Reserves more space for data if the required amount is higher than the actual capacity
            void reserve( size_type pos ){
                if(pos > v_capacity){
                    increase_size(pos);
                    for (size_type i{v_end}; i < pos; i++) v_data[i] = value_type();
                }
            };
            // Shrinks the capacity to the amount of elements inserted in the vector
            void shrink_to_fit( void ){
                if(v_capacity > v_end){
                    for(size_t i{v_end}; i < v_capacity;i++){
                        v_data[i].~T();
                    }
                    v_capacity = v_end;
                }
            };
            // Replaces the last vector with a vector of count_ amount of elements of value_ value
            void assign( size_type count_, const_reference value_ ){
                reserve(count_);
                for (size_type i{0}; i < count_; i++) v_data[i] = value_;
                v_end = count_;
            }
            // Replaces the last vector with a vector of a initializer list size amount with elements of a initializer list values
            void assign( const std::initializer_list<T>& ilist ){
                size_type s = ilist.size();
                reserve(s);
                std::copy(ilist.begin(),ilist.end(), v_data);
                v_end = s;
            }

            // Replaces the last vector with a vector of a iterators first till last values
            template < typename InputItr >
            void assign( InputItr first, InputItr last ){
                size_type s = last - first;                
                reserve(s);                
                std::copy(*first,*last, v_data);
                v_end = s;
            }

            // Erases a range of elements from the first iterator to the last iterator
            iterator erase( iterator first, iterator last ){
                iterator dummy = first;
                if(first >= this->begin() || last <= this->end()){    
                    while(last < this->end()){
                        *first = *last;
                        first++;
                        last++;
                    }
                    v_end -= last - first;  
                    return dummy;                             
                }
                else{
                     throw std::out_of_range("Position lies beyond the vector's limits!");
                }
                
             }

            // Erases a range of elements from the first const iterator to the last const iterator
            iterator erase( const_iterator first, const_iterator last ){
                if (empty()) throw std::length_error{"Cannot erase from an empty vector!"};
                iterator dummyF{first},dummyL{last};
                if(first >= this->begin() || last <= this->end()){    
                    while(dummyL <= this->end()){
                        *dummyF = *dummyL;
                        dummyF++;
                        dummyL++;
                    }
                    v_end -= dummyL - dummyF;
                    return first;
                }
                else{
                     throw std::out_of_range("Position lies beyond the vector's limits!");
                }
                
            }
            // Erases a element from the const iterator postition
             iterator erase( const_iterator pos ){
                 if (empty()) throw std::length_error{"Cannot erase from an empty vector!"};
                if(pos >= this->begin() || pos <= this->end()){       
                  v_end--;
                  for (iterator i{pos}; i < iterator{ &v_data[v_end] }; i++) *i = *(i+1);
                  return iterator(&v_data[pos]);
                }
                else{
                    throw std::out_of_range("Position lies beyond the vector's limits!");
                }
                  
              }
              // Erases a element from the iterator postition
              iterator erase( iterator pos ){
                  if (empty()) throw std::length_error{"Cannot erase from an empty vector!"};
                if(pos >= this->begin() || pos <= this->end()){       
                  v_end--;
                  for (iterator i{pos}; i < iterator{ &v_data[v_end] }; i++) *i = *(i+1);
                  return pos;
                }
                else{
                    throw std::out_of_range("Position lies beyond the vector's limits!");
                }
                  
              }

            // [V] Element access

            // Acess the constant reference of the last element of the vector
            const_reference back( void ) const{
                if (!empty()){
                    return v_data[v_end-1];
                }
                else return this->front();
            }
            // Acess the constant reference of the first element of the vector
            const_reference front( void ) const{
                return v_data[0];
            }
            // Acess the reference of the last element of the vector
            reference back( void ){
                if (!empty()){
                    return v_data[v_end-1];
                }
                else return this->front();
            }
            // Acess the reference of the first element of the vector
            reference front( void ){
                return v_data[0];
            }
            // Acess the constant reference of the pos position element of the vector
            const_reference operator[](size_type pos) const {
                return v_data[pos];
            }
            // Acess the reference of the pos position element of the vector
            reference operator[](size_type pos) {
                return v_data[pos];
            }
            // Acess the constant reference of the pos position element of the vector
            const_reference at( size_type pos) const{
                if (pos < v_end) {
                    return v_data[pos];
                }
                 else{
                     throw std::out_of_range("Position lies beyond the vector's limits!");
                } 
            }
            // Acess the reference of the pos position element of the vector
            reference at( size_type pos){
                 if (pos < v_end) {
                    return v_data[pos];
                }
                 else{
                     throw std::out_of_range("Position lies beyond the vector's limits!");
                } 
            }
            // Acess the pointer to the content inside the vector
            pointer data( void ){
                return v_data;
            }
            // Acess the constant reference to the content inside the vector
            const_reference data( void ) const{
                return v_data;
            }

            

            // [VII] Friend functions.

            // Prints the vector on a ostream
            friend std::ostream & operator<<( std::ostream & os_, const vector<T> & v_ )
            {                
                os_ << "{ ";
                for( auto i{0} ; i < v_.v_capacity ; ++i )
                {
                    if ( i == v_.v_end ) os_ << "| ";
                    os_ << v_.v_storage[ i ] << " ";
                }
                os_ << "}, Espaço Usado=" << v_.v_end << ", Espaço Alocado=" << v_.v_capacity;

                return os_;
            }
            // Swaps the contents of 2 vectors 
            friend void swap( vector<T> & first_, vector<T> & second_ )
            {
                // enable ADL
                using std::swap;

                // Swap each member of the class.
                swap( first_.v_end,      second_.v_end      );
                swap( first_.v_capacity, second_.v_capacity );
                swap( first_.v_storage,  second_.v_storage  );
            }

    };

    // [VI] Operators

    // Checks if 2 vectors are the same 
    template <typename T>
    bool operator==( const vector<T> & V1, const vector<T>& V2){
        bool result{false};
        if(V1.size() == V2.size()){
            result = true;
            for(size_t i{0}; i < V1.size();i++){
                if(V1[i] != V2[i]){
                    result = false;
                }
            }
        }
        return result;
    };
    // Checks if 2 vectors are different
    template <typename T>
    bool operator!=( const vector<T> & V1, const vector<T>& V2){
        bool result{!(V1 == V2)};
        return result;
    }

} // namespace sc.
#endif