# Roman-numbers
Transformation writing numbers from Arabic to Roman and back
//////////////////////////////////////////////////////////////////////////
//
//                              РИМСКИЕ ЧИСЛА
//
// Для записи натуральных чисел римскими цифрами используются латинские буквы.
// Каждая буква обозначает десятичное число - имеет вес:
//
// Буква -  Вес
//   I   -    1
//   V   -    5
//   X   -   10
//   L   -   50
//   C   -  100
//   D   -  500
//   M   - 1000
//
// Используя эти буквы, можно записать любое число от 1 до 3999.
// При записи чисел используются следующие правила:
//
// 1. Число, записанное римскими цифрами, читается слева направо.
// 2. Латинские буквы записываются в порядке убывания их весов. 
//    Буквы I, X, С могут быть записаны перед буквами с большими весами:
//    I может предшествовать только буквам V и Х
//    Х может предшествовать только буквам L и С
//    С может предшествовать только буквам D и М.
// 3. Буквы М, С, X, I могут повторяться в записи числа не более трех раз подряд.
//    Все остальные буквы (D, L, V) могут встречаться в записи числа только один раз.
// 4. Числовое значение определяется как сумма весов всех букв, входящих в запись числа.
//    Если буквы I, X, С записаны перед буквами с большими весами, то их веса входят в сумму со знаком минус.
//
// Пример: MMMCMXCIX = 1000+1000+1000+(-100)+1000+(-10)+100+(-1)+10=3999
//
//////////////////////////////////////////////////////////////////////////