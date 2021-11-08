#include <gtest/gtest.h>
#include <stdio.h>
// #include "../include/ring_buffer.h"
#include "../src/ring_buffer.c"

// TEST(MytestCategory,MyTest1)
// {
// 	float test_data[]={0,1,2,3,4,5,6,7,8,9,0};
// 	float average;

// 	average=calc_average(test_data,10);
	
//     EXPECT_EQ(4.5, average);
// }


TEST(init_ringbuffer, first_init) {
	ring_buffer_uint8_t buffer_data;

	uint8_t test_buff[BUFFER_LENGHT];

	init_rb(&buffer_data, &test_buff[0], &test_buff[BUFFER_LAST_ELEMENT], 0);

	// buffer head and tail should start from beginning of buffer
	EXPECT_EQ(buffer_data.buffer_head, test_buff);
	EXPECT_EQ(buffer_data.buffer_tail, test_buff);
	// buffer start should point in beginning of buffer
	EXPECT_EQ(buffer_data.buffer_start, test_buff);
	// buffer end should point end of buffer
	EXPECT_EQ(buffer_data.buffer_end, &test_buff[BUFFER_LAST_ELEMENT]);
}


/*-----------------------------------------------------*/
TEST(RingBuffer_empty_buffer, add_empty)
{
    ring_buffer_uint8_t buffer_data;
    uint8_t test_buff[BUFFER_LENGHT];
    int err;
    int i, len;

    init_rb(&buffer_data, &test_buff[0], &test_buff[BUFFER_LAST_ELEMENT], 0);

    for (i = 1; i <= BUFFER_LENGHT-1; i++) {

        // len = write_byte_to_rb(&buffer_data, 'a' + (i - 1), &err);
        write_byte_to_rb(&buffer_data, 'a' + (i - 1));

        EXPECT_EQ(buffer_data.buffer_head, test_buff + i * sizeof(unsigned char));
        EXPECT_EQ(buffer_data.buffer_tail, test_buff);
        EXPECT_EQ(buffer_data.buffer_start, test_buff);
    }

    clear_rb(&buffer_data);

    EXPECT_EQ(buffer_data.buffer_head, buffer_data.buffer_tail);
    EXPECT_EQ(buffer_data.buffer_head, test_buff + (BUFFER_LENGHT-1) * sizeof(unsigned char));
    EXPECT_EQ(buffer_data.buffer_tail, test_buff + (BUFFER_LENGHT-1) * sizeof(unsigned char));
    EXPECT_EQ(buffer_data.buffer_start, test_buff);

}


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

