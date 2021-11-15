#include <gtest/gtest.h>
#include <stdio.h>
#include "../include/include.h"
// Assertions Reference
// https://google.github.io/googletest/reference/assertions.html

TEST(init_ringbuffer, first_test) {
    struct buffer_type r_buffer;
    uint8_t test_buff[MAX_BUFFER];

    init_buffer(&r_buffer, test_buff, &test_buff[MAX_BUFFER-1], 0);
    EXPECT_EQ(r_buffer.head, test_buff);
    EXPECT_EQ(r_buffer.tail, test_buff);
    EXPECT_EQ(r_buffer.buffer_start, test_buff);
    EXPECT_EQ(r_buffer.buffer_end, test_buff + MAX_BUFFER-1);

    //Asserts
    init_buffer(&r_buffer, test_buff, &test_buff[MAX_BUFFER-1], 0);
    assert(r_buffer.head == test_buff);
    assert(r_buffer.tail == test_buff);
    assert(r_buffer.buffer_start == test_buff);
    assert(r_buffer.buffer_end == test_buff + MAX_BUFFER-1);
}


TEST(count_unread_bytes, basic_test) {
    struct buffer_type r_buffer;
    uint8_t test_buff[MAX_BUFFER];
    for (int i = 0; i < 10; i++) {
        test_buff[i] = '\0';
    }

    int state;
    int err_msg;
    int err;
    int number_unread_bits = 0;

    init_buffer(&r_buffer, test_buff, &test_buff[MAX_BUFFER-1], 0);

    for (int i = 0; i < 5; i++) {
        err = add_byte_to_buffer(&r_buffer, i + 'a', (enum error_type*)&err_msg);
        if (err == ERROR) {
            EXPECT_EQ(err_msg, 2);
        }
    }
    // print_buffer(r_buffer);
    number_unread_bits = check_byte_count_in_buffer(&r_buffer);
    EXPECT_EQ(r_buffer.tail, r_buffer.buffer_start);
    EXPECT_EQ(number_unread_bits, 5);
    EXPECT_EQ(r_buffer.tail, r_buffer.buffer_start);
    // <0,a><1,b><2,c><3,d><4,e><5, ><6, ><7, ><8, ><9, >
    //                            H
    //   T
    for (int i = 0; i < 10; i++) {
        add_byte_to_buffer(&r_buffer, i + 'a',(enum error_type*)&err);
    }
    r_buffer.tail += 6;
    // <0,f><1,g><2,h><3,i><4,j><5,a><6,b><7,c><8,d><9,e>
    //                            H
    //                                 T
    EXPECT_EQ(check_byte_count_in_buffer(&r_buffer), 9);
    r_buffer.tail -= 2;
    EXPECT_EQ(check_byte_count_in_buffer(&r_buffer), 1);
}

TEST(buffer_full_and_overwrite, basic_test) {
    struct buffer_type r_buffer;
    uint8_t test_buff[MAX_BUFFER];
    int err;
    int err_msg;
    init_buffer(&r_buffer, test_buff, &test_buff[MAX_BUFFER-1], 0);

    for (int i = 0; i < 10; i++) {
        test_buff[i] = '\0';
    }

    for (int i = 0; i < 9; i++) {
        err = add_byte_to_buffer(&r_buffer, i + 'a',(enum error_type*)&err_msg);
        if (err == ERROR) {
            EXPECT_EQ(err_msg, 2);
        }
        print_buffer(r_buffer);
    }

}

//     r.head=rx_buffer+15;       /* OR  r.head=&rx_buffer[15]; */
//     r.tail=rx_buffer+2

//     state=get_buffer_state(&r,&err);

//  /* Expected result */
//     EXPECT_EQ(state, 13);
//     EXPECT_EQ(err, OK);

//  /* These should not have moved at all*/
//     EXPECT_EQ(r.head, rx_buffer+15);
//     EXPECT_EQ(r.tail, rx_buffer+2);
//     EXPECT_EQ(r.buffer, rx_buffer);



// // /*-----------------------------------------------------*/
// TEST(RingBuffer_empty_buffer, add_empty){
//     struct buffer_type b;
//     uint8_t buff[MAX_BUFFER];
//     int err;
//     int i, len;

//     init_buffer(&b, buff);

//     for (i = 1; i <= MAX_BUFFER-1; i++) {

//         len = add_char_to_buffer(&b, 'a' + (i - 1), (enum error_type*)&err);

//         EXPECT_EQ(b.head, buff + i * sizeof(uint8_t));
//         EXPECT_EQ(b.tail, buff);
//         EXPECT_EQ(b.buffer, buff);
//     }

//     empty_buffer(&b);

//     // EXPECT_EQ(b.head, b.tail);
//     // EXPECT_EQ(b.head, buff + (MAX_BUFFER-1) * sizeof(uint8_t));
//     // EXPECT_EQ(b.tail, buff + (MAX_BUFFER-1) * sizeof(uint8_t));
//     // EXPECT_EQ(b.buffer, buff);

// }


// /****************************************************************************/

// TEST(RingBuffer_empty_buffer, empty_init)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];

//   init_buffer(&b, buff);
//   empty_buffer(&b);

//   EXPECT_EQ(b.head, buff);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }
// /*-----------------------------------------------------*/

// TEST(RingBuffer_empty_buffer, add_empty_2)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   int i;
//   int err;

//   b.head = buff + 10 * sizeof(unsigned char);
//   b.tail = buff + 1 * sizeof(unsigned char);
//   b.buffer = buff;

//   empty_buffer(&b);

//   EXPECT_EQ(b.head, buff + 10 * sizeof(unsigned char));
//   EXPECT_EQ(b.tail, buff + 10 * sizeof(unsigned char));
//   EXPECT_EQ(b.buffer, buff);

// }



// /****************************************************************************/
// TEST(RingBuffer_getbuffer, init)
// {
//   int len;
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];

//   init_buffer(&b, buff);
//   len = get_buffer_state(b);

//   EXPECT_EQ(len, 0);

//   EXPECT_EQ(b.head, buff);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }

// /*-----------------------------------------------------*/
// TEST(RingBuffer_get_buffer, add_10)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   int i, len;
//   int err;
//   unsigned char c;


//   init_buffer(&b, buff);

//   for (i = 1; i <= 10; i++)
//   {
//     len = add_char_to_buffer(&b, 'a' + ((i - 1) % 27), &err);

//     EXPECT_EQ(len, i);
//     EXPECT_EQ(b.head, buff + i);
//     EXPECT_EQ(b.tail, buff + i - 1);
//     EXPECT_EQ(b.buffer, buff);
//     EXPECT_EQ(buff[i - 1], 'a' + ((i - 1) % 27));

//     c = get_buffer_state(b);
//     EXPECT_EQ(c, 'a' + (i - 1) % 27);
//     EXPECT_EQ(b.head, buff + i);
//     EXPECT_EQ(b.tail, buff + i);
//     EXPECT_EQ(b.buffer, buff);
//   }

//   len = get_buffer_state(b);
//   EXPECT_EQ(len, 10);

//   EXPECT_EQ(b.head, buff + 10);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }


// /****************************************************************************/
// TEST(RingBuffer_add_char_to_buffer, MAX_fill)
// {
//   int err;
//   int len, i;
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   unsigned char c;


//   init_buffer(&b, buff);

//   for (i = 1; i < MAX_BUFFER; i++) {

//     len = add_char_to_buffer(&b, 'a' + (i % 27), &err);
//     EXPECT_EQ(len, i);

//     c = get_buffer_state(b);
//     EXPECT_EQ(c, 'a' + (i % 27));
//     EXPECT_EQ(b.head, buff + i);
//     EXPECT_EQ(b.tail, buff);
//     EXPECT_EQ(b.buffer, buff);
//     EXPECT_EQ(buff[i - 1], 'a' + (i % 27));
//   }

//   EXPECT_EQ(len, MAX_BUFFER - 1);
//   EXPECT_EQ(b.head, buff + MAX_BUFFER - 1);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }

// /*-----------------------------------------------------*/
// TEST(RingBuffer_add_char_to_buffer, fill_over)
// {
//   int err;
//   int len, i;
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   unsigned char c;

//   init_buffer(&b, buff);

//   for (i = 1; i <= MAX_BUFFER; i++) {

//     len = add_char_to_buffer(&b, 'a' + i - 1, &err);
//     EXPECT_EQ(len, i);

//     len = get_buffer_state(b);

//     EXPECT_EQ(len, i);
//     EXPECT_EQ(buff[i - 1], 'a' + (i - 1) % 27);
//     EXPECT_EQ(b.head, buff + i);
//     EXPECT_EQ(b.tail, buff);
//     EXPECT_EQ(b.buffer, buff);
//   }

//   SCOPED_TRACE("Full-fill");

//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ(c, 'a');

//   len = get_buffer_state(b);
//   EXPECT_EQ(len, MAX_BUFFER);

//   len = get_buffer_state(b);
//   EXPECT_EQ(len, ERROR);
//   EXPECT_EQ(err, BUFFER_FULL);

//   EXPECT_EQ(b.head, buff + i);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }


// /*-----------------------------------------------------*/
// TEST(RingBuffer_get_char_from_buffer, empty)
// {
//   int len;
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   int err;
//   unsigned char c;


//   init_buffer(&b, buff);

//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ(c, -1);
//   EXPECT_EQ(err, BUFFER_EMPTY);

//   len = get_buffer_state(b);

//   EXPECT_EQ(len, -1);
//   EXPECT_EQ(err, BUFFER_EMPTY);

//   EXPECT_EQ(b.head, buff);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }

// /*-----------------------------------------------------*/
// TEST(RingBuffer_get_char_from_buffer, one)
// {
//   int len;
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   unsigned char c;
//   int err;


//   init_buffer(&b, buff);
//   add_char_to_buffer(&b, 'a', &err);

//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ(c, 'a');

//   len = get_buffer_state(b);

//   EXPECT_EQ(len, -1);
//   EXPECT_EQ(err, OK);
//   EXPECT_EQ(b.head, buff);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }

// /*-----------------------------------------------------*/
// TEST(RingBuffer_get_char_from_buffer, multiple)
// {
//   int len, i;
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   unsigned char c;
//   int err;

//   init_buffer(&b, buff);
//   for (i = 0; i < 10; i++)
//     add_char_to_buffer(&b, 'a' + i, &err);

//   for (i = 0; i < 10; i++)
//   {
//     c = get_char_from_buffer(&b, &err);
//     EXPECT_EQ(c, 'a' + i);

//     len = get_buffer_state(b);
//     EXPECT_EQ(len, 10 - i);
//     EXPECT_EQ(err, OK);
//     EXPECT_EQ(b.head, buff + 10 - i);
//     EXPECT_EQ(b.tail, buff + 10 - i);
//     EXPECT_EQ(b.buffer, buff);

//   }

//   SCOPED_TRACE("Empty-get");

//   len = get_char_from_buffer(&b, &err);
//   EXPECT_EQ(len, -1);
//   EXPECT_EQ(err, BUFFER_EMPTY);
//   EXPECT_EQ(b.head, buff);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }
// /*-----------------------------------------------------*/
// TEST(RingBuffer_get_char_from_buffer, add_get)
// {
//   int len, i;
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   int err;


//   init_buffer(&b, buff);

//   for (i = 0; i < 10; i++)  {
//     len = add_char_to_buffer(&b, 'a', &err);
//     EXPECT_EQ(len, 1);
//     EXPECT_EQ(err, OK);
//     EXPECT_EQ(b.head, buff + i);
//     EXPECT_EQ(b.tail, buff + i - 1);
//     EXPECT_EQ(b.buffer, buff);


//     len = get_char_from_buffer(&b, &err);
//     EXPECT_EQ(len, 0);
//     EXPECT_EQ(err, OK);
//     EXPECT_EQ(b.head, buff + i + 1);
//     EXPECT_EQ(b.tail, buff + i);
//     EXPECT_EQ(b.buffer, buff);

//   }

//   len = get_char_from_buffer(&b, &err);
//   EXPECT_EQ(len, -1);
//   EXPECT_EQ(err, BUFFER_EMPTY);
//   EXPECT_EQ(b.head, buff);
//   EXPECT_EQ(b.tail, buff);
//   EXPECT_EQ(b.buffer, buff);

// }

// /*******************************************************************************/
// TEST(RingBuffer_add_char_to_buffer, big_test)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   int err;
//   int len;

//   empty_buffer(&b);
//   ASSERT_EQ(0, b.head - buff);
//   ASSERT_EQ(0, b.tail - buff);
//   ASSERT_EQ(buff, b.buffer);
//   /*-----------------------------*/

//   SCOPED_TRACE("First");
//   len = add_char_to_buffer(&b, 'a', &err);
// //EXPECT_EQ(1,len);
//   EXPECT_EQ(1, b.head - buff);
//   EXPECT_EQ(0, b.tail - buff); // must not change
//   EXPECT_EQ(buff, b.buffer); // must not change
//   EXPECT_EQ(buff[0], 'a');
//   EXPECT_EQ(BUFF_OK, err);

//   SCOPED_TRACE("Second");
//   add_char_to_buffer(&b, 'b', &err);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(2, b.head - buff);
//   EXPECT_EQ(0, b.tail - buff);
//   EXPECT_EQ(buff[1], 'b');
//   EXPECT_EQ(BUFF_OK, err);


//   SCOPED_TRACE("Third");
//   add_char_to_buffer(&b, 'c', &err);
//   EXPECT_EQ(3, b.head - buff);
//   EXPECT_EQ(0, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(buff[2], 'c');
//   EXPECT_EQ(BUFF_OK, err);

//   SCOPED_TRACE("Fourth");
//   add_char_to_buffer(&b, 'd', &err);
//   EXPECT_EQ(4, b.head - buff);
//   EXPECT_EQ(0, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(buff[3], 'd');
//   EXPECT_EQ(BUFF_OK, err);

// }

// /**************************************************************/
// TEST(RingBuffer_get_char_from_buffer, big)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   unsigned char c;
//   int err;

//   empty_buffer(&b);

//   ASSERT_EQ(0, b.head - buff);
//   ASSERT_EQ(0, b.tail - buff);
//   ASSERT_EQ(buff, b.buffer);
// //   print_buffer(b);

//   add_char_to_buffer(&b, 'a', &err);
//   //  print_buffer(b);
//   add_char_to_buffer(&b, 'b', &err);
// //   print_buffer(b);
//   add_char_to_buffer(&b, 'c', &err);
// //    print_buffer(b);
//   add_char_to_buffer(&b, 'd', &err);
//   //  print_buffer(b);
//   add_char_to_buffer(&b, 'e', &err);

//   //  print_buffer(b);

//   /*-----------------------------*/

//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ('a', c);
//   EXPECT_EQ(5, b.head - buff);
//   EXPECT_EQ(1, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(BUFF_OK, err);

//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ('b', c);
//   EXPECT_EQ(5, b.head - buff);
//   EXPECT_EQ(2, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(BUFF_OK, err);

// //   print_buffer(b);
//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ('c', c);
//   EXPECT_EQ(5, b.head - buff);
//   EXPECT_EQ(3, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(BUFF_OK, err);

//   //  print_buffer(b);
//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ('d', c);
//   EXPECT_EQ(5, b.head - buff);
//   EXPECT_EQ(4, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(BUFF_OK, err);
// //   print_buffer(b);
//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ('e', c);
//   EXPECT_EQ(5, b.head - buff);
//   EXPECT_EQ(5, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(BUFF_OK, err);

//   //  print_buffer(b);

//   /*-----------------------------*/

//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ(0, c);
//   EXPECT_EQ(0, b.head - b.tail);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(BUFFER_EMPTY, err);

//   print_buffer(b);

// }

// /*******************************************************************************/
// TEST(RingBuffer, filltest)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];
//   int i, len;

//   int err;

//   empty_buffer(&b);
//   ASSERT_EQ(0, b.head - buff);
//   ASSERT_EQ(0, b.tail - buff);
//   ASSERT_EQ(buff, b.buffer);
//   /*-----------------------------*/

//   SCOPED_TRACE("head");

// // Fill to one short
//   for (i = 0; i < MAX_BUFFER - 2; i++)
//     add_char_to_buffer(&b, 'a', &err);
//   SCOPED_TRACE("Filled");

//   EXPECT_EQ(MAX_BUFFER - 2, b.head - buff);
//   EXPECT_EQ(0, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(buff[MAX_BUFFER - 3], 'a');
//   EXPECT_EQ(BUFF_OK, err);

//   /* Fill still one */

//   len = add_char_to_buffer(&b, 'a', &err);
// //EXPECT_EQ(0,len);
//   EXPECT_EQ(MAX_BUFFER - 1, b.head - buff);
//   EXPECT_EQ(0, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(buff[MAX_BUFFER - 2], 'a');
//   EXPECT_EQ(BUFF_OK, err);

//   /* Try to fill over */

// //add_to_buffer(&b,'a',&err);
// //EXPECT_EQ(MAX_BUFFER-1,b.head-buff);
// //EXPECT_EQ(0,b.tail-buff);
// //EXPECT_EQ(buff,b.buffer);
// //EXPECT_EQ(buff[MAX_BUFFER-2],'a');
// //EXPECT_EQ(BUFFER_FULL,err);


// }
// /*******************************************************************************/
// TEST(RingBuffer, fill_get_test)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER], c;
//   int i, len;

//   int err;
//   {
//     empty_buffer(&b);
//     ASSERT_EQ(0, b.head - buff);
//     ASSERT_EQ(0, b.tail - buff);
//     ASSERT_EQ(buff, b.buffer);
//     /*-----------------------------*/

//     SCOPED_TRACE("head");
//   }
//   {
// // Fill to one short
//     for (i = 0; i < 100; i++)
//       add_char_to_buffer(&b, 'a', &err);
//     SCOPED_TRACE("Filled with 100");

// //EXPECT_EQ(MAX_BUFFER-1,len);
//     EXPECT_EQ(100, b.head - buff);
//     EXPECT_EQ(0, b.tail - buff); // tail pointer wont change
//     EXPECT_EQ(buff, b.buffer);
//     EXPECT_EQ(buff[100 - 3], 'a');
//     EXPECT_EQ(BUFF_OK, err);
//   }

//   {
//     for (i = 0; i < 100 - 1; i++)
//     {
//       c = get_char_from_buffer(&b, &err);
//       EXPECT_EQ(100, b.head - buff); // head pointer wont change
//       EXPECT_EQ(buff, b.buffer);
//       EXPECT_EQ(i + 1, b.tail - buff);
//       EXPECT_EQ(buff[100 - i - 1], 'a');
// //EXPECT_EQ(BUFF_OK,err);
//     }
//     SCOPED_TRACE("Filled with 100");
//   }
//   /*-----------------------------------*/
//   c = get_char_from_buffer(&b, &err);
//   EXPECT_EQ(100, b.head - buff); // head pointer wont change
//   EXPECT_EQ(100, b.tail - buff);
//   EXPECT_EQ(buff, b.buffer);
//   EXPECT_EQ(buff[100 - 2], 'a');
//   EXPECT_EQ(BUFF_OK, err);

// }

// /**************************************************************/

// TEST(RingBuffer_tests, empty_buffer_test)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];

//   empty_buffer(&b);

//   EXPECT_EQ(buff, b.head);
//   EXPECT_EQ(buff, b.tail);
//   EXPECT_EQ(buff, b.buffer);
// }

// /**************************************************************/

// TEST(RingBuffer, get_buffer_state)
// {
//   struct buffer_type b;
//   unsigned char buff[MAX_BUFFER];

//   empty_buffer(&b);



// }


// TEST(RingBuffer_add_string_to_buffef, string)
// {
//   struct buffer_type b;
//   int err;
//   unsigned char buff[MAX_BUFFER];
//   unsigned char str[] = "Test string";

//   empty_buffer(&b);
//   EXPECT_EQ(get_buffer_state(b), 0);

//   add_string_to_buffer(&b, str, &err);

//   EXPECT_EQ(get_buffer_state(b), 11);

// }

// TEST(RingBuffer_get_string_from_buffef, get_string)
// {
//   struct buffer_type b;
//   int err;
//   unsigned char buff[MAX_BUFFER];
//   unsigned char src[20]="Hello";
//   unsigned char dst[20];


//   add_string_to_buffer(&b, src, &err);
//   get_string_from_buffer(&b, dst, &err);

//   EXPECT_EQ(get_buffer_state(b), 11);
//   EXPECT_STREQ(src, dst);


// }

// ///**************************************************************/
// //
// //TEST(RingBuffer_tests,print_buffer)
// //{
// //
// //}

