auto RSP::r128::operator()(uint index) const -> r128 {
  static const __m128i shuffle[16] = {
    //vector
    _mm_set_epi8(15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0),  //01234567
    _mm_set_epi8(15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0),  //01234567
    //scalar quarter
    _mm_set_epi8(15,14,15,14,11,10,11,10, 7, 6, 7, 6, 3, 2, 3, 2),  //00224466
    _mm_set_epi8(13,12,13,12, 9, 8, 9, 8, 5, 4, 5, 4, 1, 0, 1, 0),  //11335577
    //scalar half
    _mm_set_epi8(15,14,15,14,15,14,15,14, 7, 6, 7, 6, 7, 6, 7, 6),  //00004444
    _mm_set_epi8(13,12,13,12,13,12,13,12, 5, 4, 5, 4, 5, 4, 5, 4),  //11115555
    _mm_set_epi8(11,10,11,10,11,10,11,10, 3, 2, 3, 2, 3, 2, 3, 2),  //22226666
    _mm_set_epi8( 9, 8, 9, 8, 9, 8, 9, 8, 1, 0, 1, 0, 1, 0, 1, 0),  //33337777
    //scalar whole
    _mm_set_epi8(15,14,15,14,15,14,15,14,15,14,15,14,15,14,15,14),  //00000000
    _mm_set_epi8(13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12),  //11111111
    _mm_set_epi8(11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10),  //22222222
    _mm_set_epi8( 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8),  //33333333
    _mm_set_epi8( 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6),  //44444444
    _mm_set_epi8( 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4),  //55555555
    _mm_set_epi8( 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2),  //66666666
    _mm_set_epi8( 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0),  //77777777
  };
  //todo: benchmark to see if testing for cases 0&1 to return value directly is faster
  return {uint128_t(_mm_shuffle_epi8(v128, shuffle[index]))};
}