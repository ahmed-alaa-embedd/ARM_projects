nel 
                                                                       only in Medium-density and Low-density Value Line devices*/
#define DAC_Trigger_T2_TRGO                ((uint32_t)0x00000024) /*!< TIM2 TRGO selected as external conversion trigger for DAC channel */
#define DAC_Trigger_T4_TRGO                ((uint32_t)0x0000002C) /*!< TIM4 TRGO selected as external conversion trigger for DAC channel */
#define DAC_Trigger_Ext_IT9                ((uint32_t)0x00000034) /*!< EXTI Line9 event selected as external conversion trigger for DAC channel */
#define DAC_Trigger_Software               ((uint32_t)0x0000003C) /*!< Conversion started by software trigger for DAC channel */

#define IS_DAC_TRIGGER(TRIGGER) (((TRIGGER) == DAC_Trigger_None) || \
                                 ((TRIGGER) == DAC_Trigger_T6_TRGO) || \
                                 ((TRIGGER) == DAC_Trigger_T8_TRGO) || \
                                 ((TRIGGER) == DAC_Trigger_T7_TRGO) || \
                                 ((TRIGGER) == DAC_Trigger_T5_TRGO) || \
                                 ((TRIGGER) == DAC_Trigger_T2_TRGO) || \
                                 ((TRIGGER) == DAC_Trigger_T4_TRGO) || \
                                 ((TRIGGER) == DAC_Trigger_Ext_IT9) || \
                                 ((TRIGGER) == DAC_Trigger_Software))

/**
  * @}
  */

/** @defgroup DAC_wave_generation 
  * @{
  */

#define DAC_WaveGeneration_None            ((uint32_t)0x00000000)
#define DAC_WaveGeneration_Noise           ((uint32_t)0x00000040)
#define DAC_WaveGeneration_Triangle        ((uint32_t)0x00000080)
#define IS_DAC_GENERATE_WAVE(WAVE) (((WAVE) == DAC_WaveGeneration_None) || \
                                    ((WAVE) == DAC_WaveGeneration_Noise) || \
                                    ((WAVE) == DAC_WaveGeneration_Triangle))
/**
  * @}
  */

/** @defgroup DAC_lfsrunmask_triangleamplitude
  * @{
  */

#define DAC_LFSRUnmask_Bit0                ((uint32_t)0x00000000) /*!< Unmask DAC channel LFSR bit0 for noise wave generation */
#define DAC_LFSRUnmask_Bits1_0             ((uint32_t)0x00000100) /*!< Unmask DAC channel LFSR bit[1:0