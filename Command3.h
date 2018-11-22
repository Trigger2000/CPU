//
//  Header.h
//  CPU
//
//  Created by Илья  on 20/11/2018.
//  Copyright © 2018 Илья . All rights reserved.
//

CMD_DEF (:, 10, (
                          {
                              *counter += 1;
                              break;
                          }))

CMD_DEF (jmp, 11, ( // здесь тоже дефайнами замени
                 {
                     *counter += 1;
                     int curlabel = bcd[*counter];
                     int cur = 0;
                     for (cur = 0; lbl[cur].labelname != curlabel; cur++)
                     {
                     }
                     *counter = lbl[cur].labelposition - 1;
                     break;
                     }))

CMD_DEF (ja, 12, (
                   {
                       if (CheckStack(foruse, 1) > CheckStack(foruse, 2))
                       {
                       *counter += 1;
                       int curlabel = bcd[*counter];
                       int cur = 0;
                       for (cur = 0; lbl[cur].labelname != curlabel; cur++)
                       {
                       }
                       *counter = lbl[cur].labelposition - 1;
                       break;
                       }
                       else
                       {
                           *counter += 1;
                           break;
                       }

                   }))

CMD_DEF (jb, 13, (
                  {
                      if (CheckStack(foruse, 1) < CheckStack(foruse, 2))
                      {
                          *counter += 1;
                          int curlabel = bcd[*counter];
                          int cur = 0;
                          for (cur = 0; lbl[cur].labelname != curlabel; cur++)
                          {
                          }
                          *counter = lbl[cur].labelposition - 1;
                          break;
                      }
                      else
                      {
                          *counter += 1;
                          break;
                      }
                  }))

CMD_DEF (je, 14, (
                  {
                      if (CheckStack(foruse, 1) == CheckStack(foruse, 2))
                      {
                          *counter += 1;
                          int curlabel = bcd[*counter];
                          int cur = 0;
                          for (cur = 0; lbl[cur].labelname != curlabel; cur++)
                          {
                          }
                          *counter = lbl[cur].labelposition - 1;
                          break;
                      }
                      else
                      {
                          *counter += 1;
                          break;
                      }

                      }))

CMD_DEF (jae, 15, (
                  {
                      if (CheckStack(foruse, 1) >= CheckStack(foruse, 2))
                      {
                          *counter += 1;
                          int curlabel = bcd[*counter];
                          int cur = 0;
                          for (cur = 0; lbl[cur].labelname != curlabel; cur++)
                          {
                          }
                          *counter = lbl[cur].labelposition - 1;
                          break;
                      }
                      else
                      {
                          *counter += 1;
                          break;
                      }

                  }))

CMD_DEF (jbe, 16, (
                  {
                      if (CheckStack(foruse, 1) <= CheckStack(foruse, 2))
                      {
                          *counter += 1;
                          int curlabel = bcd[*counter];
                          int cur = 0;
                          for (cur = 0; lbl[cur].labelname != curlabel; cur++)
                          {
                          }
                          *counter = lbl[cur].labelposition - 1;
                          break;
                      }
                      else
                      {
                          *counter += 1;
                          break;
                      }

                  }))

CMD_DEF (jne, 17, (
                  {
                      if (CheckStack(foruse, 1) != CheckStack(foruse, 2))
                      {
                          *counter += 1;
                          int curlabel = bcd[*counter];
                          int cur = 0;
                          for (cur = 0; lbl[cur].labelname != curlabel; cur++)
                          {
                          }
                          *counter = lbl[cur].labelposition - 1;
                          break;
                      }
                      else
                      {
                          *counter += 1;
                          break;
                      }

                  }))

CMD_DEF (call, 18, (
                   {
                       *counter += 1;
                       int curlabel = bcd[*counter];
                       int cur = 0;
                       for (cur = 0; lbl[cur].labelname != curlabel; cur++)
                       {
                       }
                       *returnpoint = *counter + 1;
                       *counter = lbl[cur].labelposition - 1;
                       break;
                   }))
