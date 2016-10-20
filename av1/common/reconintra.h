/*
 * Copyright (c) 2016, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

#ifndef AV1_COMMON_RECONINTRA_H_
#define AV1_COMMON_RECONINTRA_H_

#include "aom/aom_integer.h"
#include "av1/common/blockd.h"

#ifdef __cplusplus
extern "C" {
#endif

void av1_init_intra_predictors(void);

void av1_predict_intra_block(const MACROBLOCKD *xd, int bwl_in, int bhl_in,
                             TX_SIZE tx_size, PREDICTION_MODE mode,
                             const uint8_t *ref, int ref_stride, uint8_t *dst,
                             int dst_stride, int aoff, int loff, int plane);

#if CONFIG_EXT_INTER
// Mapping of interintra to intra mode for use in the intra component
static const PREDICTION_MODE interintra_to_intra_mode[INTERINTRA_MODES] = {
  DC_PRED,   V_PRED,    H_PRED,    D45_PRED, D135_PRED,
  D117_PRED, D153_PRED, D207_PRED, D63_PRED, TM_PRED
};

// Mapping of intra mode to the interintra mode
static const INTERINTRA_MODE intra_to_interintra_mode[INTRA_MODES] = {
  II_DC_PRED,   II_V_PRED,    II_H_PRED,    II_D45_PRED, II_D135_PRED,
  II_D117_PRED, II_D153_PRED, II_D207_PRED, II_D63_PRED, II_TM_PRED
};
#endif  // CONFIG_EXT_INTER
#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // AV1_COMMON_RECONINTRA_H_
