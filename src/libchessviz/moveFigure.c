#include "chess.h"

/*bool movePWhite(motion the_motion, char chess[8][8])
{
    //белая пешка?
    //тип хода?
    //взятие? берем черную фигуру?в какой клетки берем?
    //для взятие на проходе -> клетка где мы едим пустая и ниже этой клетки
    //стоит черная пешка
  printf("Start P\n");

  if (chess[the_motion.start_position_y][the_motion.start_position_x] == 'P') {
        if (the_motion.flag_ep == 1) {
            if ((chess[the_motion.end_position_y][the_motion.end_position_x]
                    == ' ') //проверка взятия на проходе если true
                && (chess[the_motion.start_position_y][the_motion.end_position_x]
                    == 'p')
                && ((the_motion.start_position_y - the_motion.end_position_y)
                    == 1) //радиус съедания
                && (abs(the_motion.start_position_x - the_motion.end_position_x)
                    == 1)) {
                //взятие пешки на проходе
                chess[the_motion.start_position_y][the_motion.end_position_x]
                        = ' '; //убираем съединую пешку
                chess[the_motion.end_position_y][the_motion.end_position_x]
                        = 'P'; //переноси пешку куда ходим
                chess[the_motion.start_position_y][the_motion.start_position_x]
                        = ' '; //удаляем пешку которой ходим
                return true;
            } else {
                return false;
            }

        case None:
            if (the_motion.type_motion) { //взятие
                if ((chess[the_motion.end_position_y][the_motion.end_position_x]
                     != ' ')
                    && (the_motion.color == White)
                    && ((the_motion.start_position_y - the_motion.end_position_y) == 1) //радиус съедания
                    && (abs(the_motion.start_position_x - the_motion.end_position_x) == 1))
                    {
                        chess[the_motion.start_position_y][the_motion.start_position_x]
                                = ' '; //убираем изначальную пешку
                        chess[the_motion.end_position_y][the_motion.end_position_x]
                                = 'P'; //переноси пешку куда ходим
                        return true; //взятие если true
                    }
                else
                    return false;
            } else {
                //тихий
                if ((the_motion.end_position_x == the_motion.start_position_x)
                    && (the_motion.end_position_y < the_motion.start_position_y)) //проверяем что идем вперед
                {
                    if (chess[the_motion.start_position_y - 1][the_motion.start_position_x]
                        == ' ') //на 1 клетку вперед нет фигуры
                    {
                        if ((chess[the_motion.start_position_y - 2][the_motion.start_position_x] == ' ') // пусто на второй клетке
                            && (the_motion.start_position_y == 1)) //ход на 2 если нужный ряд
                        {
                            //ход на 2
                            chess[the_motion.start_position_y][the_motion.start_position_x]
                                    = ' '; //убираем изначальную пешку
                            chess[the_motion.end_position_y][the_motion.end_position_x]
                                    = 'P'; //переноси пешку куда ходим
                            return true;
                        } else {
                            //ход на 1
                            chess[the_motion.start_position_y]
                                 [the_motion.start_position_x]
                                    = ' '; //убираем изначальную пешку
                            chess[the_motion.end_position_y]
                                 [the_motion.end_position_x]
                                    = 'P'; //переноси пешку куда ходим
                            return true;
                                }
                    } else
                        return false;
                } else
                    return false;
            }
            break;
        case flag_transformation:
            if (the_motion.end_position_y == 0) {
                if (the_motion.type_motion) // взятие по диагонали вперед
                {
                  if (islower(chess[the_motion.end_position_y][the_motion.end_position_x])
                      && ((the_motion.start_position_y - the_motion.end_position_y)
                          == 1) //радиус съедания
                      && (abs(the_motion.start_position_x - the_motion.end_position_x)
                          == 1))
                      {
                          chess[the_motion.start_position_y][the_motion.start_position_x]
                                  = ' '; //убираем изначальную пешку
                          chess[the_motion.end_position_y][the_motion.end_position_x]
                                  = the_motion.transformation_figure; //ставим фигуру
                          return true; //взятие если true
                      }
                  else
                      return false;
                } else { // тихий ход вперед
                    if ((the_motion.end_position_x == the_motion.start_position_x)
                        && (the_motion.end_position_y < the_motion.start_position_y)) //проверяем что идем вперед
                    {
                        if (chess[the_motion.start_position_y - 1][the_motion.start_position_x] == ' ') //на 1 клетку вперед нет фигуры
                        {
                            chess[the_motion.start_position_y][the_motion.start_position_x]
                                    = ' '; //убираем изначальную пешку
                            chess[the_motion.end_position_y][the_motion.end_position_x]
                                    = the_motion.transformation_figure; //ставим фигуру
                            return true;
                        }
                    }
                }
            } else
                return false;
            break;
        case flag_shah:
            break;
        case flag_cmate:
            break;
        }
  } else return false;

  return false;
}
*/



bool movePWhite(motion the_motion, char chess[8][8]) {
  if (chess[the_motion.start_position_y][the_motion.start_position_x] == 'P') {
    if (the_motion.flag_ep == 1) {
          if ((chess[the_motion.end_position_y][the_motion.end_position_x]
                  == ' ') //проверка взятия на проходе если true
              && (chess[the_motion.start_position_y][the_motion.end_position_x]
                  == 'p')
              && ((the_motion.start_position_y - the_motion.end_position_y)
                  == 1) //радиус съедания
              && (abs(the_motion.start_position_x - the_motion.end_position_x)
                  == 1)) {
              //взятие пешки на проходе
              chess[the_motion.start_position_y][the_motion.end_position_x]
                      = ' '; //убираем съединую пешку
              chess[the_motion.end_position_y][the_motion.end_position_x]
                      = 'P'; //переноси пешку куда ходим
              chess[the_motion.start_position_y][the_motion.start_position_x]
                      = ' '; //удаляем пешку которой ходим
              return true;
          } else {
              return false;
          }

    } else if (the_motion.flag_transformation == 1) {
                if (the_motion.type_motion) // взятие по диагонали вперед
                {
                  if (islower(chess[the_motion.end_position_y][the_motion.end_position_x])
                      && ((the_motion.start_position_y - the_motion.end_position_y)
                          == 1) //радиус съедания
                      && (abs(the_motion.start_position_x - the_motion.end_position_x)
                          == 1))
                      {
                          chess[the_motion.start_position_y][the_motion.start_position_x]
                                  = ' '; //убираем изначальную пешку
                          chess[the_motion.end_position_y][the_motion.end_position_x]
                                  = the_motion.transformation_figure; //ставим фигуру
                          return true; //взятие если true
                      }
                  else
                      return false;
                } else { // тихий ход вперед
                    if ((the_motion.end_position_x == the_motion.start_position_x)
                        && (the_motion.end_position_y < the_motion.start_position_y)) //проверяем что идем вперед
                    {
                        if (chess[the_motion.start_position_y - 1][the_motion.start_position_x] == ' ') //на 1 клетку вперед нет фигуры
                        {
                            chess[the_motion.start_position_y][the_motion.start_position_x]
                                    = ' '; //убираем изначальную пешку
                            chess[the_motion.end_position_y][the_motion.end_position_x]
                                    = the_motion.transformation_figure; //ставим фигуру
                            return true;
                        }
                    }
                }
    } else {
      if (the_motion.type_motion) { //взятие
          if ((chess[the_motion.end_position_y][the_motion.end_position_x]
               != ' ')
              && (the_motion.color == White)
              && ((the_motion.start_position_y - the_motion.end_position_y) == 1) //радиус съедания
              && (abs(the_motion.start_position_x - the_motion.end_position_x) == 1))
              {
                  chess[the_motion.start_position_y][the_motion.start_position_x]
                          = ' '; //убираем изначальную пешку
                  chess[the_motion.end_position_y][the_motion.end_position_x]
                          = 'P'; //переноси пешку куда ходим
                  return true; //взятие если true
              }
          else
              return false;
      } else {
          //тихий
          if ((the_motion.end_position_x == the_motion.start_position_x)
              && (the_motion.end_position_y < the_motion.start_position_y)) //проверяем что идем вперед
          {
              if (chess[the_motion.start_position_y - 1][the_motion.start_position_x]
                  == ' ') //на 1 клетку вперед нет фигуры
              {
                  if ((chess[the_motion.start_position_y - 2][the_motion.start_position_x] == ' ') // пусто на второй клетке
                      && (the_motion.start_position_y == 1)) //ход на 2 если нужный ряд
                  {
                      //ход на 2
                      chess[the_motion.start_position_y][the_motion.start_position_x]
                              = ' '; //убираем изначальную пешку
                      chess[the_motion.end_position_y][the_motion.end_position_x]
                              = 'P'; //переноси пешку куда ходим
                      return true;
                  } else {
                      //ход на 1
                      chess[the_motion.start_position_y]
                           [the_motion.start_position_x]
                              = ' '; //убираем изначальную пешку
                      chess[the_motion.end_position_y]
                           [the_motion.end_position_x]
                              = 'P'; //переноси пешку куда ходим
                      return true;
                  }
              } else return false;
          } else return false;
      }
    }
  } else return false;
  return false;
}


/*bool movePBlack(motion the_motion, char chess[8][8])
{
    //черная пешка?
    //тип хода?
    //взятие? берем черную фигуру?в какой клетки берем?
    //для взятие на проходе -> клетка где мы едим пустая и ниже этой клетки
    //стоит черная пешка
  printf("Start p\n");

  if (chess[the_motion.start_position_y][the_motion.start_position_x] == 'p') {
        switch (the_motion.event_) {
        case Ep:
            if ((chess[the_motion.end_position_y][the_motion.end_position_x]
                 == ' ') //проверка взятия на проходе если true
                && (chess[the_motion.start_position_y][the_motion.end_position_x]
                    == 'P')
                && ((the_motion.end_position_y - the_motion.start_position_y)
                    == 1) //радиус съедания
                && (abs(the_motion.start_position_x - the_motion.end_position_x)
                    == 1)) {
                //взятие пешки на проходе
                chess[the_motion.start_position_y][the_motion.end_position_x]
                        = ' '; //убираем съединую пешку
                chess[the_motion.end_position_y][the_motion.end_position_x]
                        = 'p'; //переноси пешку куда ходим
                chess[the_motion.start_position_y][the_motion.start_position_x]
                        = ' '; //удаляем пешку которой ходим
                return true;
            } else {
                return false;
            }
            break;
        case None:
            if (the_motion.type_motion) { //взятие
                if ((chess[the_motion.end_position_y][the_motion.end_position_x]
                     != ' ')
                    && (the_motion.color == Black)
                    && ((the_motion.end_position_y - the_motion.start_position_y)
                        == 1) //радиус съедания
                    && (abs(the_motion.start_position_x - the_motion.end_position_x)
                        == 1))
                    {
                        chess[the_motion.start_position_y][the_motion.start_position_x]
                                = ' '; //убираем изначальную пешку
                        chess[the_motion.end_position_y][the_motion.end_position_x]
                                = 'p'; //переноси пешку куда ходим
                        return true; //взятие если true
                    }
                else
                    return false;
            } else {
                //тихий
                if ((the_motion.end_position_x == the_motion.start_position_x)
                    && (the_motion.end_position_y > the_motion.start_position_y)) //проверяем что идем вперед
                {
                    if (chess[the_motion.start_position_y + 1][the_motion.start_position_x]
                        == ' ') //на 1 клетку вперед нет фигуры
                    {
                        if ((chess[the_motion.start_position_y + 2][the_motion.start_position_x] == ' ') // пусто на второй клетке
                            && (the_motion.start_position_y == 1)) //ход на 2 если нужный ряд
                        {
                            //ход на 2
                            chess[the_motion.start_position_y][the_motion.start_position_x]
                                    = ' '; //убираем изначальную пешку
                            chess[the_motion.end_position_y][the_motion.end_position_x]
                                    = 'p'; //переноси пешку куда ходим
                            return true;
                        } else {
                            //ход на 1
                            chess[the_motion.start_position_y]
                                 [the_motion.start_position_x]
                                    = ' '; //убираем изначальную пешку
                            chess[the_motion.end_position_y]
                                 [the_motion.end_position_x]
                                    = 'p'; //переноси пешку куда ходим
                            return true;
                                }
                    } else
                        return false;
                } else
                    return false;
            }
            break;
        case Transformation:
            if (the_motion.end_position_y == 7) {
                if (the_motion.type_motion) // взятие по диагонали вперед
                {
                  if (isupper(chess[the_motion.end_position_y][the_motion.end_position_x])
                      && ((the_motion.end_position_y - the_motion.start_position_y)
                          == 1) //радиус съедания
                      && (abs(the_motion.start_position_x - the_motion.end_position_x)
                          == 1))
                      {
                          chess[the_motion.start_position_y][the_motion.start_position_x]
                                  = ' '; //убираем изначальную пешку
                          chess[the_motion.end_position_y][the_motion.end_position_x]
                                  = the_motion.trans_fig; //ставим фигуру
                          return true; //взятие если true
                      }
                  else
                      return false;
                } else { // тихий ход вперед
                    if ((the_motion.end_position_x == the_motion.start_position_x)
                        && (the_motion.end_position_y > the_motion.start_position_y)) //проверяем что идем вперед
                    {
                        if (chess[the_motion.start_position_y - 1][the_motion.start_position_x] == ' ') //на 1 клетку вперед нет фигуры
                        {
                            chess[the_motion.start_position_y][the_motion.start_position_x]
                                    = ' '; //убираем изначальную пешку
                            chess[the_motion.end_position_y][the_motion.end_position_x]
                                    = the_motion.trans_fig; //ставим фигуру
                            return true;
                        }
                    }
                }
            } else
                return false;
            break;
        case Shah:
            break;
        case CMate:
            break;
        }
  } else return false;

  return false;
}
*/





bool movePBlack(motion the_motion, char chess[8][8]) {
  if (chess[the_motion.start_position_y][the_motion.start_position_x] == 'p') {
     if (the_motion.flag_ep == 1) {
       if ((chess[the_motion.end_position_y][the_motion.end_position_x]
               == ' ') //проверка взятия на проходе если true
           && (chess[the_motion.start_position_y][the_motion.end_position_x]
               == 'P')
           && ((the_motion.end_position_y - the_motion.start_position_y)
               == 1) //радиус съедания
           && (abs(the_motion.start_position_x - the_motion.end_position_x)
               == 1)) {
           //взятие пешки на проходе
           chess[the_motion.start_position_y][the_motion.end_position_x]
                   = ' '; //убираем съединую пешку
           chess[the_motion.end_position_y][the_motion.end_position_x]
                   = 'p'; //переноси пешку куда ходим
           chess[the_motion.start_position_y][the_motion.start_position_x]
                   = ' '; //удаляем пешку которой ходим
           return true;
         } else {
             return false;
         }
     } else if (the_motion.flag_transformation == 1) {
       if (the_motion.end_position_y == 7) {
           if (the_motion.type_motion) // взятие по диагонали вперед
           {
             if (isupper(chess[the_motion.end_position_y][the_motion.end_position_x])
                 && ((the_motion.end_position_y - the_motion.start_position_y)
                     == 1) //радиус съедания
                 && (abs(the_motion.start_position_x - the_motion.end_position_x)
                     == 1))
                 {
                     chess[the_motion.start_position_y][the_motion.start_position_x]
                             = ' '; //убираем изначальную пешку
                     chess[the_motion.end_position_y][the_motion.end_position_x]
                             = tolower(the_motion.transformation_figure); //ставим фигуру
                     return true; //взятие если true
                 }
             else
                 return false;
           } else { // тихий ход вперед
               if ((the_motion.end_position_x == the_motion.start_position_x)
                   && (the_motion.end_position_y > the_motion.start_position_y)) //проверяем что идем вперед
               {
                   if (chess[the_motion.start_position_y - 1][the_motion.start_position_x] == ' ') //на 1 клетку вперед нет фигуры
                   {
                       chess[the_motion.start_position_y][the_motion.start_position_x]
                               = ' '; //убираем изначальную пешку
                       chess[the_motion.end_position_y][the_motion.end_position_x]
                               = tolower(the_motion.transformation_figure); //ставим фигуру
                       return true;
                   }
               }
           }
        }
     } else {
       if (the_motion.type_motion) { //взятие
           if ((chess[the_motion.end_position_y][the_motion.end_position_x]
                != ' ')
               && (the_motion.color == Black)
               && ((the_motion.end_position_y - the_motion.start_position_y)
                   == 1) //радиус съедания
               && (abs(the_motion.start_position_x - the_motion.end_position_x)
                   == 1))
               {
                   chess[the_motion.start_position_y][the_motion.start_position_x]
                           = ' '; //убираем изначальную пешку
                   chess[the_motion.end_position_y][the_motion.end_position_x]
                           = 'p'; //переноси пешку куда ходим
                   return true; //взятие если true
               }
           else
               return false;
       } else {
           //тихий
           if ((the_motion.end_position_x == the_motion.start_position_x)
               && (the_motion.end_position_y > the_motion.start_position_y)) //проверяем что идем вперед
           {
               if (chess[the_motion.start_position_y + 1][the_motion.start_position_x]
                   == ' ') //на 1 клетку вперед нет фигуры
               {
                   if ((chess[the_motion.start_position_y + 2][the_motion.start_position_x] == ' ') // пусто на второй клетке
                       && (the_motion.start_position_y == 1)) //ход на 2 если нужный ряд
                   {
                       //ход на 2
                       chess[the_motion.start_position_y][the_motion.start_position_x]
                               = ' '; //убираем изначальную пешку
                       chess[the_motion.end_position_y][the_motion.end_position_x]
                               = 'p'; //переноси пешку куда ходим
                       return true;
                   } else {
                       //ход на 1
                       chess[the_motion.start_position_y]
                            [the_motion.start_position_x]
                               = ' '; //убираем изначальную пешку
                       chess[the_motion.end_position_y]
                            [the_motion.end_position_x]
                               = 'p'; //переносим пешку куда ходим
                       return true;
                           }
               } else
                   return false;
           } else
               return false;
       }
     }
  } else return false;
  return false;
}

bool moveB(motion the_motion, char chess[8][8]) {
    return false;
}

bool moveN(motion the_motion, char chess[8][8]) {
    return false;
}

bool moveK(motion the_motion, char chess[8][8]) {
    return false;
}

bool moveQ(motion the_motion, char chess[8][8]) {
    return false;
}

bool moveR(motion the_motion, char chess[8][8]) {
    return false;
}
