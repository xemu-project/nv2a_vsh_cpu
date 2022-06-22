#include "nv2a_vsh_emulator_execution_state.h"

#include <string.h>

Nv2aVshExecutionState nv2a_vsh_emu_initialize_full_execution_state(
    Nv2aVshCPUFullExecutionState *state) {
  memset(state, 0, sizeof(*state));
  Nv2aVshExecutionState ret = {
      (float *)state->input_regs, (float *)state->output_regs,
      (float *)state->temp_regs, (float *)state->context_regs,
      (float *)&state->address_reg, NULL};
  return ret;
}

Nv2aVshExecutionState nv2a_vsh_emu_initialize_xss_execution_state(
    Nv2aVshCPUXVSSExecutionState *state, float *context_regs,
    bool *context_dirty) {
  memset(state, 0, sizeof(*state));
  state->context_regs = context_regs;
  state->context_dirty = context_dirty;
  Nv2aVshExecutionState ret = {
      (float *)state->input_regs, (float *)state->output_regs,
      (float *)state->temp_regs, (float *)state->context_regs,
      (float *)&state->address_reg, state->context_dirty};
  return ret;
}
