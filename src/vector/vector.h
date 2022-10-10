
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

/// Sequence container namespace.
namespace sc {
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
            size_type v_capacity;   //!< Storge capacity.
            size_type v_end;        //!< How many elements currently stored in the array.
            pointer v_data;         //!< Stores the data.
            size_type s;
        public:
            //=== [I] SPECIAL MEMBERS (6 OF THEM)

            // Initialize the vector empty with or without a especific capacity
            explicit vector( size_type cp = 0 ){ 
                v_data = new T[cp];
                v_capacity = cp;
                v_end = 0; 
            }
            //Destrutor do Vecotr
            virtual ~vector( void ){
                 if (v_data != nullptr) delete[] v_data;
            }
            // Initialize the vector from another vector
            vector(const vector & target){
                v_capacity = target.size();
                v_data = new T[v_capacity];
                v_end = v_capacity;  // Array começa vazio.
                // Copy the elements from the il into the array.
                std::copy(target.begin(),target.end(), v_data);
            }
            // Inicialize the vector from a initializer list
            vector( std::initializer_list<T> target){
                v_capacity = target.size();
                v_data = new T[v_capacity];
                v_end = v_capacity;  // Array começa vazio.
                // Copy the elements from the il into the array.
                std::copy(target.begin(),target.end(), v_data);
            }

            vector( vector && );
            template < typename InputItr >
            vector( InputItr, InputItr );

            // Initialize the vector form the "=" operator using another vector
            vector & operator=( const vector & target){
                v_capacity = target.size();
                v_data = new T[v_capacity];
                v_end = v_capacity;  // Array começa vazio.
                // Copy the elements from the il into the array.
                std::copy(target.begin(),target.end(), v_data);
            }


            vector & operator=( vector && target){
                vector(target);
            }

            //=== [II] ITERATORS
            iterator begin( void ){
                return &v_data[0];
            };
            iterator end( void ){
                return &v_data[v_end];
            }
            const_iterator cbegin( void ) const{
                return &v_data[0];
            }
            const_iterator cend( void ) const{
                return &v_data[v_end];
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
                m_end = 0;
            }
            void push_front( const_reference value){
                if (full()) {
                    v_capacity = v_capacity + 2^s++;
                }
                v_data[] = value;
            }
            void push_back( const_reference value){
                 if (full()) {
                    v_capacity = v_capacity + 2^s++;
                }
                v_data[m_end++] = value;
            }
            void pop_back( void );
            void pop_front( void );

            iterator insert( iterator pos_ , const_reference value_ ){
                if (pos < v_end){
                    for (size_type i{v_end}; i > 0; --i) m_data[i] = m_data[i - 1];
                }
                else{
                     
                    for (size_type i{m_end}; i < pos; ++i) v_data[i] = value_type();
                
                 
                } // ==> Case C: [m_capacity,infinito)
                    
                v_data[pos] = value;
                    // Update size.
                v_end = std::max(pos+1,m_end+1);
            };
            iterator insert( const_iterator pos_ , const_reference value_ );

            template < typename InputItr >
            iterator insert( iterator pos_ , InputItr first_, InputItr last_ );
            template < typename InputItr >
            iterator insert( const_iterator pos_ , InputItr first_, InputItr last_ );

            iterator insert( iterator pos_, const std::initializer_list< value_type >& ilist_ );
            iterator insert( const_iterator pos_, const std::initializer_list< value_type >& ilist_ );

            void reserve( size_type );
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

            iterator erase( iterator first, iterator last );
            iterator erase( const_iterator first, const_iterator last );

            iterator erase( const_iterator pos );
            iterator erase( iterator pos );

            // [V] Element access
            const_reference back( void ) const{
                return &v_data[m_end-1];
            }
            const_reference front( void ) const{
                return &v_data[0];
            }
            reference back( void ){
                return &v_data[m_end-1];
            }
            reference front( void ){
                return &v_data[0];
            }
            const_reference operator[](size_type pos) const {
                return v_data[pos];
            }
            reference operator[](size_type pos) {
                return v_data[pos];
            }
            const_reference at( size_type ) const;
            reference at( size_type );
            pointer data( void ){
                return &v_data;
            }
            const_reference data( void ) const{
                return v_data;
            }

            

            // [VII] Friend functions.
            friend std::ostream & operator<<( std::ostream & os_, const vector<T> & v_ )
            {
                // O que eu quero imprimir???
                os_ << "{ ";
                for( auto i{0u} ; i < v_.m_capacity ; ++i )
                {
                    if ( i == v_.m_end ) os_ << "| ";
                    os_ << v_.m_storage[ i ] << " ";
                }
                os_ << "}, m_end=" << v_.m_end << ", m_capacity=" << v_.m_capacity;

                return os_;
            }
            friend void swap( vector<T> & first_, vector<T> & second_ )
            {
                // enable ADL
                using std::swap;

                // Swap each member of the class.
                swap( first_.m_end,      second_.m_end      );
                swap( first_.m_capacity, second_.m_capacity );
                swap( first_.m_storage,  second_.m_storage  );
            }

        private:
            bool full( void ) const{
                return v_end == v_capacity;
            }

            size_type m_end;                //!< The list's current size (or index past-last valid element).
            size_type m_capacity;           //!< The list's storage capacity.
            std::unique_ptr<T[]> m_storage; //!< The list's data storage area.
    };

    // [VI] Operators
    template <typename T>
    bool operator==( const vector<T> &, const vector<T>& );
    template <typename T>
    bool operator!=( const vector<T> &, const vector<T>& );

} // namespace sc.
#endif