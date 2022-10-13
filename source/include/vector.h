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

            iterator& operator+=(difference_type offset){
                iterator &it{*this};
                it+=offset;
                // TODO
                return it;
            }
            iterator& operator-=(difference_type offset){
                iterator &it{*this};
                it-=offset;
                // TODO
                return it;
            }

            friend bool operator<(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr < itb.m_ptr;
            }
            friend bool operator>(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr > itb.m_ptr;
            }
            friend bool operator>=(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr >= itb.m_ptr;
            }
            friend bool operator<=(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr <= itb.m_ptr;
            }

            friend iterator operator+( difference_type offset, iterator it ){
                // TODO
                iterator dummy = offset + it;
                return dummy;
            }
            friend iterator operator+( iterator it, difference_type offset ){
                // TODO
                iterator dummy = it + offset;
                return dummy;
            }
            friend iterator operator-( iterator it, difference_type offset ){
                // TODO
                iterator dummy = it - offset;
                return dummy;
            }            
            friend iterator operator-(difference_type offset , iterator it){
                // TODO
                iterator dummy = offset - it;
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

            iterator& operator+=(difference_type offset){
                iterator &it{*this};
                it+=offset;
                // TODO
                return it;
            }
            iterator& operator-=(difference_type offset){
                iterator &it{*this};
                it-=offset;
                // TODO
                return it;
            }

            friend bool operator<(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr < itb.m_ptr;
            }
            friend bool operator>(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr > itb.m_ptr;
            }
            friend bool operator>=(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr >= itb.m_ptr;
            }
            friend bool operator<=(const iterator& ita, const iterator& itb){
                // TODO
                return ita.m_ptr <= itb.m_ptr;
            }

            friend iterator operator+( difference_type offset, iterator it ){
                // TODO
                iterator dummy = offset + it;
                return dummy;
            }
            friend iterator operator+( iterator it, difference_type offset ){
                // TODO
                iterator dummy = it + offset;
                return dummy;
            }
            friend iterator operator-( iterator it, difference_type offset ){
                // TODO
                iterator dummy = it - offset;
                return dummy;
            }            
            friend iterator operator-(difference_type offset , iterator it){
                // TODO
                iterator dummy = offset - it;
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

            void increase_size( size_type amount = 0){
                v_capacity += amount + pow(2, s++);
                pointer new_data = new T[v_capacity];
                std::copy(this->begin(),this->end(),new_data);    
                this->~vector();
                v_data = new_data;                
            }

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
            // Inicialize the vector from a initializer list
            vector( std::initializer_list<T> target){
                v_capacity = target.size();
                v_data = new T[v_capacity];
                v_end = target.size();  // Vector Starts Full
                // Copy the elements from the target into the Vector
                std::copy(target.begin(),target.end(), v_data);
            }

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
                v_end = target.size();  // Vector Starts Fuçç
                // Copy the elements from the target into the Vector.
                std::copy(target.cbegin(),target.cend(), v_data);
            }


            //=== [II] ITERATORS
            iterator begin( void ){
                return iterator(&v_data[0]);
            }
            iterator end( void ){
                return iterator(&v_data[v_end]);
            }
            const_iterator cbegin( void ) const{
                return const_iterator(&v_data[0]);
            }
            const_iterator cend( void ) const{
                return const_iterator(&v_data[v_end]);
            }

            // [III] Capacity
            size_type size( void ) const{
                return v_end;
            }
            size_type capacity( void ) const{
                return v_capacity;
            }
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
            void push_front( const_reference value){
                if (full()) {
                    increase_size();
                }
                for (size_type i{v_end}; i > 0; --i) v_data[i] = v_data[i-1];
                v_data[0] = value;
            }
            void push_back( const_reference value){
                 if (full()) {
                    increase_size();
                }
                v_data[v_end++] = value;
            }
            void pop_back( void ){
                v_data[v_end-1].~T();
                v_end--;
            }
            void pop_front( void ){
                v_end--;
                for (size_type i{0}; i < v_end; i++) v_data[i] = v_data[i+1];
                v_data[v_end].~T();
                
            }

            iterator insert( iterator pos_ , const_reference value_ ){
                if (pos_ < v_end){
                    for (size_type i{v_end}; i > 0; --i) v_data[i] = v_data[i - 1];
                }
                else if(pos_ > v_capacity){                    
                    increase_size(pos_);              
                }                     
                v_data[pos_] = value_;
                    // Update size.
                v_end = std::max(pos_+1,v_end+1);
                return iterator(&v_data[pos_]);
            };
            iterator insert( const_iterator pos_ , const_reference value_ ){
                 if (pos_ < v_end){
                    for (size_type i{v_end}; i > 0; --i) v_data[i] = v_data[i - 1];
                }
                else if(pos_ > v_capacity){                    
                    increase_size(pos_);              
                }                     
                v_data[pos_] = value_;
                    // Update size.
                v_end = std::max(pos_+1,v_end+1);
                return iterator(&v_data[pos_]);
            }

            template < typename InputItr >
            iterator insert( iterator pos_ , InputItr first_, InputItr last_ );
            template < typename InputItr >
            iterator insert( const_iterator pos_ , InputItr first_, InputItr last_ );

            iterator insert( iterator pos_, const std::initializer_list< value_type >& ilist_ );
            iterator insert( const_iterator pos_, const std::initializer_list< value_type >& ilist_ );

            void reserve( size_type pos ){
                increase_size(pos);
            };
            void shrink_to_fit( void ){
                if(v_capacity > v_end){
                    for(size_t i{v_end}; i < v_capacity;i++){
                        v_data[i].~T();
                    }
                    v_capacity = v_end-1;
                }
            };

            void assign( size_type count_, const_reference value_ );
            void assign( const std::initializer_list<T>& ilist );
            template < typename InputItr >
            void assign( InputItr first, InputItr last );

            iterator erase( iterator first, iterator last ){
                iterator dummy = first;
                if(first >= this->begin() || last <= this->end()){    
                    while(last < v_end){
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
            iterator erase( const_iterator first, const_iterator last ){
                if (empty()) throw std::length_error{"Cannot erase from an empty vector!"};
                iterator dummyF{first},dummyL{last};
                if(first >= this->begin() || last <= this->end()){    
                    while(dummyL <= v_end){
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
              iterator erase( iterator pos ){
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

            // [V] Element access
            const_reference back( void ) const{
                if (!empty()){
                    return v_data[v_end-1];
                }
                else return this->front();
            }
            const_reference front( void ) const{
                return v_data[0];
            }
            reference back( void ){
                if (!empty()){
                    return v_data[v_end-1];
                }
                else return this->front();
            }
            reference front( void ){
                return v_data[0];
            }
            const_reference operator[](size_type pos) const {
                return v_data[pos];
            }
            reference operator[](size_type pos) {
                return v_data[pos];
            }
            const_reference at( size_type pos) const{
                return v_data[pos];
            }
            reference at( size_type pos){
                return v_data[pos];
            }
            pointer data( void ){
                return v_data;
            }
            const_reference data( void ) const{
                return v_data;
            }

            

            // [VII] Friend functions.
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
    template <typename T>
    bool operator==( const vector<T> & V1, const vector<T>& V2){
        bool result{true};
        if(V1.size() == V2.size()){
            for(size_t i{0}; i < V1.size();i++){
                if(V1[i] != V2[i]){
                    result = false;
                }
            }
        }
        return result;
    };
    template <typename T>
    bool operator!=( const vector<T> & V1, const vector<T>& V2){
        bool result{!(V1 == V2)};
        return result;
    }

} // namespace sc.
#endif