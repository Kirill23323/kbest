#include <stdlib.h>
#include <string.h>

// Функция, которую компилятор не может оптимизировать
volatile int sink;

void __attribute__((noinline)) trigger_asan() {
    // Выделяем буфер в куче
    char *buffer = (char*)malloc(10);
    
    // Используем volatile указатель чтобы компилятор не оптимизировал доступ
    volatile char *volatile_buffer = buffer;
    
    // Записываем за границы буфера - heap-buffer-overflow
    for (int i = 0; i < 15; i++) {
        volatile_buffer[i] = 'A';  // Запись за границы
        sink = volatile_buffer[i]; // Чтение за границы
    }
    
    // Используем после освобождения - use-after-free
    free(buffer);
    buffer[5] = 'B';  // Запись в освобожденную память
    sink = buffer[3]; // Чтение из освобожденной памяти
    
    // Двойное освобождение - double-free
    free(buffer);
}

// Дополнительные тесты для разных типов ошибок
void __attribute__((noinline)) stack_buffer_overflow() {
    volatile char stack_buffer[5];
    for (int i = 0; i < 10; i++) {
        stack_buffer[i] = 'C';  // Stack buffer overflow
        sink = stack_buffer[i];
    }
}

void __attribute__((noinline)) memory_leak() {
    volatile char *leak = (volatile char*)malloc(20);
    for (int i = 0; i < 20; i++) {
        leak[i] = 'D';
        sink = leak[i];
    }
    // Намеренно не освобождаем - memory leak
}

int main() {
    // Вызываем все тестовые функции
    trigger_asan();
    stack_buffer_overflow();
    memory_leak();
    
    return 0;
}