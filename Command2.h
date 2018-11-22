//
//  Header.h
//  CPU
//
//  Created by Илья  on 20/11/2018.
//  Copyright © 2018 Илья . All rights reserved.
//

CMD_DEF (push, 1, (
                   {
                       *counter += 1;
                       StackPush(foruse, bcd[*counter], logs);
                       break;
                   }))

CMD_DEF (push_rax, 101, (
                         {
                             double par = 0;
                             StackPop(foruse, &par);
                             registers[0] = par;
                             break;
                         }))

CMD_DEF (push_rbx, 102, (
                         {
                             double par = 0;
                             StackPop(foruse, &par);
                             registers[1] = par;
                             break;
                         }))

CMD_DEF (push_rcx, 103, (
                         {
                             double par = 0;
                             StackPop(foruse, &par);
                             registers[2] = par;
                             break;
                         }))

CMD_DEF (push_rdx, 104, (
                         {
                             double par = 0;
                             StackPop(foruse, &par);
                             registers[3] = par;
                             break;
                         }))

CMD_DEF (pop_rax, 201, (
                        {
                            StackPush(foruse, registers[0], logs);
                            break;
                        }))

CMD_DEF (pop_rbx, 202, (
                        {
                            StackPush(foruse, registers[1], logs);
                            break;
                        }))

CMD_DEF (pop_rcx, 203, (
                        {
                            StackPush(foruse, registers[2], logs);
                            break;
                        }))

CMD_DEF (pop_rdx, 204, (
                        {
                            StackPush(foruse, registers[3], logs);
                            break;
                        }))
