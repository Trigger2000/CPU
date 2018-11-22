//
//  Header.h
//  CPU
//
//  Created by Илья  on 19/11/2018.
//  Copyright © 2018 Илья . All rights reserved.
//

CMD_DEF (next_is_cmd, 0, (
                   {
                       *counter += 1;
                       *com = bcd[*counter];
                       comanalyzer(com, logs, bcd, counter, foruse, checker, registers, lbl, returnpoint);
                       break;
                   }))
CMD_DEF (add, 2, (
                  {
                      double par1 = 0, par2 = 0, par = 0;
                      StackPop(foruse, &par1);
                      StackPop(foruse, &par2);
                      par = par1 + par2;
                      StackPush(foruse, par, logs);
                      break;
                  }))

CMD_DEF (sub, 3, (
                  {
                      double par1 = 0, par2 = 0, par = 0;
                      StackPop(foruse, &par1);
                      StackPop(foruse, &par2);
                      par = par2 - par1;
                      StackPush(foruse, par, logs);
                      break;
                  }))

CMD_DEF (mul, 4, (
                  {
                      double par1 = 0, par2 = 0, par = 0;
                      StackPop(foruse, &par1);
                      StackPop(foruse, &par2);
                      par = par1 * par2;
                      StackPush(foruse, par, logs); //сделать новый дефайн для операций
                      break;
                  }))

CMD_DEF (div, 5, (
                  {
                      double par1 = 0, par2 = 0, par = 0;
                      StackPop(foruse, &par1);
                      StackPop(foruse, &par2);
                      par = par2 / par1;
                      StackPush(foruse, par, logs);
                      break;
                  }))

CMD_DEF (Out, 6, (
                  {
                      double par = 0;
                      par = CheckStack(foruse, 1);
                      printf("%lf\n", par);
                      break;
                  }))

CMD_DEF (end, 7, (
                  {
                      *checker = 1;
                      break;
                  }))

CMD_DEF (sqrt, 8, (
                   {
                       double par = 0, par1 = 0;
                       StackPop(foruse, &par1);
                       par = sqrt(par1);
                       StackPush(foruse, par, logs);
                       break;
                   }))

CMD_DEF (sqr, 9, (
                  {
                      double par = 0, par1 = 0;
                      StackPop(foruse, &par1);
                      par = pow(par1, 2);
                      StackPush(foruse, par, logs);
                      break;
                  }))

CMD_DEF (ret, 19, (
                   {
                       *counter = *returnpoint;
                       break;
                   }))

CMD_DEF (noroots, 20, (
                   {
                       printf("no roots\n");
                       break;
                   }))

CMD_DEF (inf, 21, (
                       {
                           printf("Infinity number of roots\n");
                           break;
                       }))
