#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <utility>

template<typename T>
class Vector {
public:
    // ����������� �� ���������
    Vector() : _size(0), _capacity(0), _data(nullptr) {}

    // ����������
    ~Vector() {
        delete[] _data;
    }

    // ���������� �������� � ����� �������
    void push_back(const T& value) {
        if (_size >= _capacity) {
            if (_capacity == 0) _capacity = 1;
            else _capacity *= 2;
            T* newData = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) {
                newData[i] = _data[i];
            }
            delete[] _data;
            _data = newData;
        }
        _data[_size++] = value;
    }

    // ��������� �������� �� �������
    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // ��������� ������� �������
    size_t size() const {
        return _size;
    }

private:
    size_t _size;       // ������� ������ �������
    size_t _capacity;   // ������� ������� (���������� ���������� ������)
    T* _data;           // ��������� �� ������ ���������
};


