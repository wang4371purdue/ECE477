/**
  ******************************************************************************
  * @file    stm32f0xx.h
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    05-December-2014
  * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral register's definitions, bits 
  *          definitions and memory mapping for STM32F0xx devices.  
  *          
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The device used in the target application
  *              - To use or not the peripheral’s drivers in application code(i.e. 
  *                code will be based on direct access to peripheral’s registers 
  *                rather than drivers API), this option is controlled by 
  *                "#define USE_STDPERIPH_DRIVER"
  *              - To change few application-specific parameters such as the HSE 
  *                crystal frequency
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral’s registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f0xx
  * @{
  */
    
#ifndef __STM32F0XX_H
#define __STM32F0XX_H

#ifdef __cplusplus
 extern "C" {
#endif 
  
/** @addtogroup Library_configuration_section
  * @{
  */
  
/* Uncomment the line below according to the target STM32F0 device used in your 
   application 
  */

#if !defined (STM32F030) && !defined (STM32F031) && !defined (STM32F051) && \
    !defined (STM32F072) && !defined (STM32F042) && !defined (STM32F091) && \
    !defined (STM32F070xB) && !defined (STM32F070x6) && !defined (STM32F030xC)
  /* #define STM32F030 */   
  /* #define STM32F031 */   
  /* #define STM32F051 */   
  /* #define STM32F072 */
  /* #define STM32F070xB */   
  /* #define STM32F042 */
  /* #define STM32F070x6 */   
  /* #define STM32F091 */
  /* #define STM32F030xC */  
#endif /* STM32F030 || STM32F031 || STM32F051 || STM32F072 || STM32F042 || STM32F091 ||
          STM32F070xB || STM32F070x6 || STM32F030xC */

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */

/* Old STM32F0XX definition, maintained for legacy purpose */
#if defined(STM32F0XX) || defined(STM32F0XX_MD) 
  #define STM32F051
#endif /* STM32F0XX */

/* Old STM32F0XX_LD definition, maintained for legacy purpose */
#ifdef STM32F0XX_LD
  #define     STM32F031
#endif /* STM32F0XX_LD */

/* Old STM32F0XX_HD definition, maintained for legacy purpose */
#ifdef STM32F0XX_HD
   #define   STM32F072
#endif /* STM32F0XX_HD */

/* Old STM32F030X6/X8 definition, maintained for legacy purpose */
#if defined (STM32F030X8) || defined (STM32F030X6)
  #define    STM32F030
#endif /* STM32F030X8 or  STM32F030X6 */


#if !defined (STM32F030) && !defined (STM32F031) && !defined (STM32F051) && \
    !defined (STM32F072) && !defined (STM32F042) && !defined (STM32F091) && \
    !defined (STM32F070xB) && !defined (STM32F070x6) && !defined (STM32F030xC)
 #error "Please select first the target STM32F0xx device used in your application (in stm32f0xx.h file)"
#endif /* STM32F030 || STM32F031 || STM32F051 || STM32F072 || STM32F042 || STM32F091 ||
          STM32F070xB || STM32F070x6 || STM32F030xC */

#if !defined  USE_STDPERIPH_DRIVER
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will 
   be based on direct access to peripherals registers 
   */
  /*#define USE_STDPERIPH_DRIVER*/
#endif /* USE_STDPERIPH_DRIVER */

/**
 * @brief In the following line adjust the value of External High Speed oscillator (HSE)
   used in your application 
   
   Tip: To avoid modifying this file each time you need to use different HSE, you
        can define the HSE value in your toolchain compiler preprocessor.
  */
#if !defined  (HSE_VALUE)     
#define HSE_VALUE    ((uint32_t)8000000) /*!< Value of the External oscillator in Hz*/
#endif /* HSE_VALUE */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) Startup 
   Timeout value 
   */
#if !defined  (HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSE start up */
#endif /* HSE_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the Internal High Speed oscillator (HSI) Startup 
   Timeout value 
   */
#if !defined  (HSI_STARTUP_TIMEOUT)
#define HSI_STARTUP_TIMEOUT   ((uint16_t)0x5000) /*!< Time out for HSI start up */
#endif /* HSI_STARTUP_TIMEOUT */

#if !defined  (HSI_VALUE) 
#define HSI_VALUE  ((uint32_t)8000000) /*!< Value of the Internal High Speed oscillator in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI_VALUE */

#if !defined  (HSI14_VALUE) 
#define HSI14_VALUE ((uint32_t)14000000) /*!< Value of the Internal High Speed oscillator for ADC in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI14_VALUE */

#if !defined  (HSI48_VALUE) 
#define HSI48_VALUE ((uint32_t)48000000) /*!< Value of the Internal High Speed oscillator for USB in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI48_VALUE */

#if !defined  (LSI_VALUE) 
#define LSI_VALUE  ((uint32_t)40000)    /*!< Value of the Internal Low Speed oscillator in Hz
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* LSI_VALUE */

#if !defined  (LSE_VALUE) 
#define LSE_VALUE  ((uint32_t)32768)    /*!< Value of the External Low Speed oscillator in Hz */
#endif /* LSE_VALUE */

/**
 * @brief STM32F0xx Standard Peripheral Library version number V1.4.0
   */
#define __STM32F0XX_STDPERIPH_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __STM32F0XX_STDPERIPH_VERSION_SUB1   (0x05) /*!< [23:16] sub1 version */
#define __STM32F0XX_STDPERIPH_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __STM32F0XX_STDPERIPH_VERSION_RC     (0x00) /*!< [7:0]  release candidate */ 
#define __STM32F0XX_STDPERIPH_VERSION        ((__STM32F0XX_STDPERIPH_VERSION_MAIN << 24)\
                                             |(__STM32F0XX_STDPERIPH_VERSION_SUB1 << 16)\
                                             |(__STM32F0XX_STDPERIPH_VERSION_SUB2 << 8)\
                                             |(__STM32F0XX_STDPERIPH_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
 * @brief STM32F0xx Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
#define __CM0_REV                 0 /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             0 /*!< STM32F0xx do not provide MPU                  */
#define __NVIC_PRIO_BITS          2 /*!< STM32F0xx uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0 /*!< Set to 1 if different SysTick Config is used  */

/*!< Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ******************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                        */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                          */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                          */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                      */

#if defined (STM32F051)
/******  STM32F051  specific Interrupt Numbers *************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detect Interrupt                  */
  RTC_IRQn                    = 2,      /*!< RTC through EXTI Line Interrupt                         */
  FLASH_IRQn                  = 3,      /*!< FLASH Interrupt                                         */
  RCC_IRQn                    = 4,      /*!< RCC Interrupt                                           */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                            */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                            */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                            */
  TS_IRQn                     = 8,      /*!< Touch sense controller Interrupt                        */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                 */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupts                 */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1, COMP1 and COMP2 Interrupts                        */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts  */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                          */
  TIM2_IRQn                   = 15,     /*!< TIM2 Interrupt                                          */
  TIM3_IRQn                   = 16,     /*!< TIM3 Interrupt                                          */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 and DAC Interrupts                                 */
  TIM14_IRQn                  = 19,     /*!< TIM14 Interrupt                                         */
  TIM15_IRQn                  = 20,     /*!< TIM15 Interrupt                                         */
  TIM16_IRQn                  = 21,     /*!< TIM16 Interrupt                                         */
  TIM17_IRQn                  = 22,     /*!< TIM17 Interrupt                                         */
  I2C1_IRQn                   = 23,     /*!< I2C1 Interrupt                                          */
  I2C2_IRQn                   = 24,     /*!< I2C2 Interrupt                                          */
  SPI1_IRQn                   = 25,     /*!< SPI1 Interrupt                                          */
  SPI2_IRQn                   = 26,     /*!< SPI2 Interrupt                                          */
  USART1_IRQn                 = 27,     /*!< USART1 Interrupt                                        */
  USART2_IRQn                 = 28,     /*!< USART2 Interrupt                                        */
  CEC_IRQn                    = 30      /*!< CEC Interrupt                                           */
#elif defined (STM32F031)
/******  STM32F031 specific Interrupt Numbers *************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detect Interrupt                  */
  RTC_IRQn                    = 2,      /*!< RTC through EXTI Line Interrupt                         */
  FLASH_IRQn                  = 3,      /*!< FLASH Interrupt                                         */
  RCC_IRQn                    = 4,      /*!< RCC Interrupt                                           */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                            */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                            */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                            */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                 */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupts                 */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                          */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts  */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                          */
  TIM2_IRQn                   = 15,     /*!< TIM2 Interrupt                                          */
  TIM3_IRQn                   = 16,     /*!< TIM3 Interrupt                                          */
  TIM14_IRQn                  = 19,     /*!< TIM14 Interrupt                                         */
  TIM16_IRQn                  = 21,     /*!< TIM16 Interrupt                                         */
  TIM17_IRQn                  = 22,     /*!< TIM17 Interrupt                                         */
  I2C1_IRQn                   = 23,     /*!< I2C1 Interrupt                                          */
  SPI1_IRQn                   = 25,     /*!< SPI1 Interrupt                                          */
  USART1_IRQn                 = 27      /*!< USART1 Interrupt                                        */
#elif defined (STM32F030)
/******  STM32F030 specific Interrupt Numbers *************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  RTC_IRQn                    = 2,      /*!< RTC through EXTI Line Interrupt                         */
  FLASH_IRQn                  = 3,      /*!< FLASH Interrupt                                         */
  RCC_IRQn                    = 4,      /*!< RCC Interrupt                                           */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                            */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                            */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                            */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                 */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupts                 */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                          */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts  */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                          */
  TIM3_IRQn                   = 16,     /*!< TIM3 Interrupt                                          */
  TIM14_IRQn                  = 19,     /*!< TIM14 Interrupt                                         */
  TIM15_IRQn                  = 20,     /*!< TIM15 Interrupt                                         */
  TIM16_IRQn                  = 21,     /*!< TIM16 Interrupt                                         */
  TIM17_IRQn                  = 22,     /*!< TIM17 Interrupt                                         */
  I2C1_IRQn                   = 23,     /*!< I2C1 Interrupt                                          */
  I2C2_IRQn                   = 24,     /*!< I2C2 Interrupt                                          */
  SPI1_IRQn                   = 25,     /*!< SPI1 Interrupt                                          */
  SPI2_IRQn                   = 26,     /*!< SPI2 Interrupt                                          */
  USART1_IRQn                 = 27,     /*!< USART1 Interrupt                                        */
  USART2_IRQn                 = 28      /*!< USART2 Interrupt                                        */
#elif defined (STM32F072)
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                     */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD and VDDIO2 supply comparator through EXTI Line detect Interrupt */
  RTC_IRQn                    = 2,      /*!< RTC through EXTI Line Interrupt                               */
  FLASH_IRQn                  = 3,      /*!< FLASH Interrupt                                               */
  RCC_CRS_IRQn                = 4,      /*!< RCC and CRS Interrupts                                        */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                                  */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                                  */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                                  */
  TSC_IRQn                    = 8,      /*!< TSC Interrupt                                                 */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                      */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                       */
  DMA1_Channel4_5_6_7_IRQn    = 11,     /*!< DMA1 Channel 4, Channel 5, Channel 6 and Channel 7 Interrupts */
  ADC1_COMP_IRQn              = 12,     /*!< ADC1, COMP1 and COMP2 Interrupts                              */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts        */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                */
  TIM2_IRQn                   = 15,     /*!< TIM2 Interrupt                                                */
  TIM3_IRQn                   = 16,     /*!< TIM3 Interrupt                                                */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 and DAC Interrupts                                       */
  TIM7_IRQn                   = 18,     /*!< TIM7 Interrupts                                               */
  TIM14_IRQn                  = 19,     /*!< TIM14 Interrupt                                               */
  TIM15_IRQn                  = 20,     /*!< TIM15 Interrupt                                               */
  TIM16_IRQn                  = 21,     /*!< TIM16 Interrupt                                               */
  TIM17_IRQn                  = 22,     /*!< TIM17 Interrupt                                               */
  I2C1_IRQn                   = 23,     /*!< I2C1 Interrupt                                                */
  I2C2_IRQn                   = 24,     /*!< I2C2 Interrupt                                                */
  SPI1_IRQn                   = 25,     /*!< SPI1 Interrupt                                                */
  SPI2_IRQn                   = 26,     /*!< SPI2 Interrupt                                                */
  USART1_IRQn                 = 27,     /*!< USART1 Interrupt                                              */
  USART2_IRQn                 = 28,     /*!< USART2 Interrupt                                              */
  USART3_4_IRQn               = 29,     /*!< USART3 and USART4 Interrupts                                  */
  CEC_CAN_IRQn                = 30,     /*!< CEC and CAN Interrupts                                        */
  USB_IRQn                    = 31      /*!< USB Low Priority global Interrupt                             */
#elif defined (STM32F042)
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                     */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD and VDDIO2 supply comparator through EXTI Line detect Interrupt */
  RTC_IRQn                    = 2,      /*!< RTC through EXTI Line Interrupt                               */
  FLASH_IRQn                  = 3,      /*!< FLASH Interrupt                                               */
  RCC_CRS_IRQn                = 4,      /*!< RCC and CRS Interrupts                                        */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                                  */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                                  */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                                  */
  TSC_IRQn                    = 8,      /*!< TSC Interrupt                                                 */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                      */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                       */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4, Channel 5 Interrupts                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupts                                               */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts        */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                */
  TIM2_IRQn                   = 15,     /*!< TIM2 Interrupt                                                */
  TIM3_IRQn                   = 16,     /*!< TIM3 Interrupt                                                */
  TIM14_IRQn                  = 19,     /*!< TIM14 Interrupt                                               */
  TIM16_IRQn                  = 21,     /*!< TIM16 Interrupt                                               */
  TIM17_IRQn                  = 22,     /*!< TIM17 Interrupt                                               */
  I2C1_IRQn                   = 23,     /*!< I2C1 Interrupt                                                */
  SPI1_IRQn                   = 25,     /*!< SPI1 Interrupt                                                */
  SPI2_IRQn                   = 26,     /*!< SPI2 Interrupt                                                */
  USART1_IRQn                 = 27,     /*!< USART1 Interrupt                                              */
  USART2_IRQn                 = 28,     /*!< USART2 Interrupt                                              */
  CEC_CAN_IRQn                = 30,     /*!< CEC and CAN Interrupts                                        */
  USB_IRQn                    = 31      /*!< USB Low Priority global Interrupt                             */
#elif defined (STM32F091)
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                       */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD & VDDIO2 Interrupts through EXTI Lines 16 and 31            */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS Global Interrupts                                     */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                                    */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                                    */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                                    */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Ch1_IRQn               = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Ch2_3_DMA2_Ch1_2_IRQn  = 10,     /*!< DMA1 Channel 2 and 3 & DMA2 Channel 1 and 2 Interrupts          */
  DMA1_Ch4_7_DMA2_Ch3_5_IRQn  = 11,     /*!< DMA1 Channel 4 to 7 & DMA2 Channel 3 to 5 Interrupts            */
  ADC1_COMP_IRQn               = 12,     /*!< ADC, COMP1 and COMP2 Interrupts (EXTI Lines 21 and 22)          */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts          */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_DAC_IRQn               = 17,     /*!< TIM6 global and DAC channel underrun error Interrupts           */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt & EXTI Line24 Interrupt (I2C2 wakeup)      */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_8_IRQn               = 29,     /*!< USART3 to USART8 global Interrupts                              */
  CEC_CAN_IRQn                = 30      /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
#elif defined (STM32F070xB)
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                       */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC Global Interrupts                                           */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                                    */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                                    */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                                    */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                         */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupts                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 interrupts (ADC interrupt combined with EXTI Lines 21 and 22 */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts          */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_IRQn                   = 17,     /*!< TIM6 global Interrupts                                          */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt                                         */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  USART3_4_IRQn               = 29,     /*!< USART3 and USART4 global Interrupts                             */
  USB_IRQn                    = 31      /*!< USB global Interrupts & EXTI Line18 Interrupt                   */
#elif defined (STM32F070x6)
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                       */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC Global Interrupts                                     */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                                    */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                                    */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                                    */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                         */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupts                         */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts          */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  USB_IRQn                    = 31      /*!< USB global Interrupts & EXTI Line18 Interrupt                   */
#elif defined (STM32F030xC)
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                       */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_IRQn                    = 4,      /*!< RCC Global Interrupts                                           */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupts                                    */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupts                                    */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupts                                    */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                         */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupts                         */
  ADC1_IRQn                   = 12,     /*!< ADC Interrupts                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupts          */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM6_IRQn                   = 17,     /*!< TIM6 global Interrupts                                          */
  TIM7_IRQn                   = 18,     /*!< TIM7 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM15_IRQn                  = 20,     /*!< TIM15 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  I2C2_IRQn                   = 24,     /*!< I2C2 Event Interrupt                                            */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup) */
  USART3_6_IRQn               = 29,     /*!< USART3 to USART6 global Interrupts                              */
#endif /* STM32F051 */
}IRQn_Type;

/**
  * @}
  */

#include "core_cm0.h"
#include "system_stm32f0xx.h"
#include <stdint.h>

/** @addtogroup Exported_types
  * @{
  */  

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Analog to Digital Converter  
  */

typedef struct
{
  __IO uint32_t ISR;          /*!< ADC Interrupt and Status register,                          Address offset:0x00 */
  __IO uint32_t IER;          /*!< ADC Interrupt Enable register,                              Address offset:0x04 */
  __IO uint32_t CR;           /*!< ADC Control register,                                       Address offset:0x08 */
  __IO uint32_t CFGR1;        /*!< ADC Configuration register 1,                               Address offset:0x0C */
  __IO uint32_t CFGR2;        /*!< ADC Configuration register 2,                               Address offset:0x10 */
  __IO uint32_t SMPR;         /*!< ADC Sampling time register,                                 Address offset:0x14 */
  uint32_t   RESERVED1;       /*!< Reserved,                                                                  0x18 */
  uint32_t   RESERVED2;       /*!< Reserved,                                                                  0x1C */
  __IO uint32_t TR;           /*!< ADC watchdog threshold register,                            Address offset:0x20 */
  uint32_t   RESERVED3;       /*!< Reserved,                                                                  0x24 */
  __IO uint32_t CHSELR;       /*!< ADC channel selection register,                             Address offset:0x28 */
  uint32_t   RESERVED4[5];    /*!< Reserved,                                                                  0x2C */
   __IO uint32_t DR;          /*!< ADC data register,                                          Address offset:0x40 */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CCR;
} ADC_Common_TypeDef;


/** 
  * @brief Controller Area Network TxMailBox 
  */
typedef struct
{
  __IO uint32_t TIR;  /*!< CAN TX mailbox identifier register */
  __IO uint32_t TDTR; /*!< CAN mailbox data length control and time stamp register */
  __IO uint32_t TDLR; /*!< CAN mailbox data low register */
  __IO uint32_t TDHR; /*!< CAN mailbox data high register */
} CAN_TxMailBox_TypeDef;

/** 
  * @brief Controller Area Network FIFOMailBox 
  */
typedef struct
{
  __IO uint32_t RIR;  /*!< CAN receive FIFO mailbox identifier register */
  __IO uint32_t RDTR; /*!< CAN receive FIFO mailbox data length control and time stamp register */
  __IO uint32_t RDLR; /*!< CAN receive FIFO mailbox data low register */
  __IO uint32_t RDHR; /*!< CAN receive FIFO mailbox data high register */
} CAN_FIFOMailBox_TypeDef;
  
/** 
  * @brief Controller Area Network FilterRegister 
  */
typedef struct
{
  __IO uint32_t FR1; /*!< CAN Filter bank register 1 */
  __IO uint32_t FR2; /*!< CAN Filter bank register 1 */
} CAN_FilterRegister_TypeDef;

/** 
  * @brief Controller Area Network 
  */
typedef struct
{
  __IO uint32_t              MCR;                 /*!< CAN master control register,         Address offset: 0x00          */
  __IO uint32_t              MSR;                 /*!< CAN master status register,          Address offset: 0x04          */
  __IO uint32_t              TSR;                 /*!< CAN transmit status register,        Address offset: 0x08          */
  __IO uint32_t              RF0R;                /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
  __IO uint32_t              RF1R;                /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
  __IO uint32_t              IER;                 /*!< CAN interrupt enable register,       Address offset: 0x14          */
  __IO uint32_t              ESR;                 /*!< CAN error status register,           Address offset: 0x18          */
  __IO uint32_t              BTR;                 /*!< CAN bit timing register,             Address offset: 0x1C          */
  uint32_t                   RESERVED0[88];       /*!< Reserved, 0x020 - 0x17F                                            */
  CAN_TxMailBox_TypeDef      sTxMailBox[3];       /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];     /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
  uint32_t                   RESERVED1[12];       /*!< Reserved, 0x1D0 - 0x1FF                                            */
  __IO uint32_t              FMR;                 /*!< CAN filter master register,          Address offset: 0x200         */
  __IO uint32_t              FM1R;                /*!< CAN filter mode register,            Address offset: 0x204         */
  uint32_t                   RESERVED2;           /*!< Reserved, 0x208                                                    */
  __IO uint32_t              FS1R;                /*!< CAN filter scale register,           Address offset: 0x20C         */
  uint32_t                   RESERVED3;           /*!< Reserved, 0x210                                                    */
  __IO uint32_t              FFA1R;               /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
  uint32_t                   RESERVED4;           /*!< Reserved, 0x218                                                    */
  __IO uint32_t              FA1R;                /*!< CAN filter activation register,      Address offset: 0x21C         */
  uint32_t                   RESERVED5[8];        /*!< Reserved, 0x220-0x23F                                              */
  CAN_FilterRegister_TypeDef sFilterRegister[28]; /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
} CAN_TypeDef;

/** 
  * @brief HDMI-CEC 
  */

typedef struct
{
  __IO uint32_t CR;           /*!< CEC control register,                                       Address offset:0x00 */
  __IO uint32_t CFGR;         /*!< CEC configuration register,                                 Address offset:0x04 */
  __IO uint32_t TXDR;         /*!< CEC Tx data register ,                                      Address offset:0x08 */
  __IO uint32_t RXDR;         /*!< CEC Rx Data Register,                                       Address offset:0x0C */
  __IO uint32_t ISR;          /*!< CEC Interrupt and Status Register,                          Address offset:0x10 */
  __IO uint32_t IER;          /*!< CEC interrupt enable register,                              Address offset:0x14 */
}CEC_TypeDef;

/**
  * @brief Comparator 
  */

typedef struct
{
  __IO uint32_t CSR;     /*!< COMP comparator control and status register, Address offset: 0x1C */
} COMP_TypeDef;


/** 
  * @brief CRC calculation unit 
  */

typedef struct
{
  __IO uint32_t DR;          /*!< CRC Data register,                           Address offset: 0x00 */
  __IO uint8_t  IDR;         /*!< CRC Independent data register,               Address offset: 0x04 */
  uint8_t       RESERVED0;   /*!< Reserved,                                                    0x05 */
  uint16_t      RESERVED1;   /*!< Reserved,                                                    0x06 */
  __IO uint32_t CR;          /*!< CRC Control register,                        Address offset: 0x08 */
  uint32_t      RESERVED2;   /*!< Reserved,                                                    0x0C */
  __IO uint32_t INIT;        /*!< Initial CRC value register,                  Address offset: 0x10 */
  __IO uint32_t POL;         /*!< CRC polynomial register,                     Address offset: 0x14 */
} CRC_TypeDef;

/**
  * @brief Clock Recovery System 
  */
typedef struct 
{
__IO uint32_t CR;     /*!< CRS ccontrol register,              Address offset: 0x00 */
__IO uint32_t CFGR;   /*!< CRS configuration register,         Address offset: 0x04 */
__IO uint32_t ISR;    /*!< CRS interrupt and status register,  Address offset: 0x08 */
__IO uint32_t ICR;    /*!< CRS interrupt flag clear register,  Address offset: 0x0C */
} CRS_TypeDef;

/** 
  * @brief Digital to Analog Converter
  */

typedef struct
{
  __IO uint32_t CR;       /*!< DAC control register,                                    Address offset: 0x00 */
  __IO uint32_t SWTRIGR;  /*!< DAC software trigger register,                           Address offset: 0x04 */
  __IO uint32_t DHR12R1;  /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
  __IO uint32_t DHR12L1;  /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
  __IO uint32_t DHR8R1;   /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
  __IO uint32_t DHR12R2;  /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
  __IO uint32_t DHR12L2;  /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
  __IO uint32_t DHR8R2;   /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
  __IO uint32_t DHR12RD;  /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
  __IO uint32_t DHR12LD;  /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
  __IO uint32_t DHR8RD;   /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
  __IO uint32_t DOR1;     /*!< DAC channel1 data output register,                       Address offset: 0x2C */
  __IO uint32_t DOR2;     /*!< DAC channel2 data output register,                       Address offset: 0x30 */
  __IO uint32_t SR;       /*!< DAC status register,                                     Address offset: 0x34 */
} DAC_TypeDef;

/** 
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;       /*!< MCU device ID code,                          Address offset: 0x00 */
  __IO uint32_t CR;           /*!< Debug MCU configuration register,            Address offset: 0x04 */
  __IO uint32_t APB1FZ;       /*!< Debug MCU APB1 freeze register,              Address offset: 0x08 */
  __IO uint32_t APB2FZ;       /*!< Debug MCU APB2 freeze register,              Address offset: 0x0C */
}DBGMCU_TypeDef;

/** 
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CCR;          /*!< DMA channel x configuration register                                           */
  __IO uint32_t CNDTR;        /*!< DMA channel x number of data register                                          */
  __IO uint32_t CPAR;         /*!< DMA channel x peripheral address register                                      */
  __IO uint32_t CMAR;         /*!< DMA channel x memory address register                                          */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;          /*!< DMA interrupt status register,                            Address offset: 0x00 */
  __IO uint32_t IFCR;         /*!< DMA interrupt flag clear register,                        Address offset: 0x04 */
  uint32_t      RESERVED0[40];/*!< Reserved as declared by channel typedef                         0x08 - 0xA4*/
  __IO uint32_t RMPCR;        /*!< Remap control register,                                      Address offset: 0xA8 */
}DMA_TypeDef;

/** 
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t IMR;          /*!<EXTI Interrupt mask register,                             Address offset: 0x00 */
  __IO uint32_t EMR;          /*!<EXTI Event mask register,                                 Address offset: 0x04 */
  __IO uint32_t RTSR;         /*!<EXTI Rising trigger selection register ,                  Address offset: 0x08 */
  __IO uint32_t FTSR;         /*!<EXTI Falling trigger selection register,                  Address offset: 0x0C */
  __IO uint32_t SWIER;        /*!<EXTI Software interrupt event register,                   Address offset: 0x10 */
  __IO uint32_t PR;           /*!<EXTI Pending register,                                    Address offset: 0x14 */
}EXTI_TypeDef;

/** 
  * @brief FLASH Registers
  */
typedef struct
{
  __IO uint32_t ACR;          /*!<FLASH access control register,                 Address offset: 0x00 */
  __IO uint32_t KEYR;         /*!<FLASH key register,                            Address offset: 0x04 */
  __IO uint32_t OPTKEYR;      /*!<FLASH OPT key register,                        Address offset: 0x08 */
  __IO uint32_t SR;           /*!<FLASH status register,                         Address offset: 0x0C */
  __IO uint32_t CR;           /*!<FLASH control register,                        Address offset: 0x10 */
  __IO uint32_t AR;           /*!<FLASH address register,                        Address offset: 0x14 */
  __IO uint32_t RESERVED;     /*!< Reserved,                                                     0x18 */
  __IO uint32_t OBR;          /*!<FLASH option bytes register,                   Address offset: 0x1C */
  __IO uint32_t WRPR;         /*!<FLASH option bytes register,                   Address offset: 0x20 */
} FLASH_TypeDef;


/** 
  * @brief Option Bytes Registers
  */
typedef struct
{
  __IO uint16_t RDP;          /*!< FLASH option byte Read protection,             Address offset: 0x00 */
  __IO uint16_t USER;         /*!< FLASH option byte user options,                Address offset: 0x02 */
  __IO uint16_t DATA0;        /*!< User data byte 0 (stored in FLASH_OBR[23:16]), Address offset: 0x04 */
  __IO uint16_t DATA1;        /*!< User data byte 1 (stored in FLASH_OBR[31:24]), Address offset: 0x06 */
  __IO uint16_t WRP0;         /*!< FLASH option byte write protection 0,          Address offset: 0x08 */
  __IO uint16_t WRP1;         /*!< FLASH option byte write protection 1,          Address offset: 0x0A */
  __IO uint16_t WRP2;         /*!< FLASH option byte write protection 2,          Address offset: 0x0C */
  __IO uint16_t WRP3;         /*!< FLASH option byte write protection 3,          Address offset: 0x0E */
} OB_TypeDef;
  

/** 
  * @brief General Purpose IO
  */

typedef struct
{
  __IO uint32_t MODER;        /*!< GPIO port mode register,                                  Address offset: 0x00 */
  __IO uint16_t OTYPER;       /*!< GPIO port output type register,                           Address offset: 0x04 */
  uint16_t RESERVED0;         /*!< Reserved,                                                                 0x06 */
  __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,                          Address offset: 0x08 */
  __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
  __IO uint16_t IDR;          /*!< GPIO port input data register,                            Address offset: 0x10 */
  uint16_t RESERVED1;         /*!< Reserved,                                                                 0x12 */
  __IO uint16_t ODR;          /*!< GPIO port output data register,                           Address offset: 0x14 */
  uint16_t RESERVED2;         /*!< Reserved,                                                                 0x16 */
  __IO uint32_t BSRR;         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
  __IO uint32_t LCKR;         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
  __IO uint32_t AFR[2];       /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
  __IO uint16_t BRR;          /*!< GPIO bit reset register,                                  Address offset: 0x28 */
  uint16_t RESERVED3;         /*!< Reserved,                                                                 0x2A */
}GPIO_TypeDef;

/** 
  * @brief SysTem Configuration
  */

typedef struct
{
  __IO uint32_t CFGR1;          /*!< SYSCFG configuration register 1,                        Address offset: 0x00 */
       uint32_t RESERVED;       /*!< Reserved,                                                               0x04 */
  __IO uint32_t EXTICR[4];      /*!< SYSCFG external interrupt configuration register,  Address offset: 0x14-0x08 */
  __IO uint32_t CFGR2;          /*!< SYSCFG configuration register 2,                        Address offset: 0x18 */
       uint32_t RESERVED1[25];  /*!< Reserved + COMP,							                                           0x1C */
  __IO uint32_t IT_LINE_SR[32]; /*!< SYSCFG configuration IT_LINE register,                  Address offset: 0x80 */
       
}SYSCFG_TypeDef;

/** 
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;      /*!< I2C Control register 1,            Address offset: 0x00 */
  __IO uint32_t CR2;      /*!< I2C Control register 2,            Address offset: 0x04 */
  __IO uint32_t OAR1;     /*!< I2C Own address 1 register,        Address offset: 0x08 */
  __IO uint32_t OAR2;     /*!< I2C Own address 2 register,        Address offset: 0x0C */
  __IO uint32_t TIMINGR;  /*!< I2C Timing register,               Address offset: 0x10 */
  __IO uint32_t TIMEOUTR; /*!< I2C Timeout register,              Address offset: 0x14 */
  __IO uint32_t ISR;      /*!< I2C Interrupt and status register, Address offset: 0x18 */
  __IO uint32_t ICR;      /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  __IO uint32_t PECR;     /*!< I2C PEC register,                  Address offset: 0x20 */
  __IO uint32_t RXDR;     /*!< I2C Receive data register,         Address offset: 0x24 */
  __IO uint32_t TXDR;     /*!< I2C Transmit data register,        Address offset: 0x28 */
}I2C_TypeDef;


/** 
  * @brief Independent WATCHDOG
  */
typedef struct
{
  __IO uint32_t KR;   /*!< IWDG Key register,       Address offset: 0x00 */
  __IO uint32_t PR;   /*!< IWDG Prescaler register, Address offset: 0x04 */
  __IO uint32_t RLR;  /*!< IWDG Reload register,    Address offset: 0x08 */
  __IO uint32_t SR;   /*!< IWDG Status register,    Address offset: 0x0C */
  __IO uint32_t WINR; /*!< IWDG Window register,    Address offset: 0x10 */
} IWDG_TypeDef;

/** 
  * @brief Power Control
  */

typedef struct
{
  __IO uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
  __IO uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;


/** 
  * @brief Reset and Clock Control
  */
typedef struct
{
  __IO uint32_t CR;         /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t CFGR;       /*!< RCC clock configuration register,                            Address offset: 0x04 */
  __IO uint32_t CIR;        /*!< RCC clock interrupt register,                                Address offset: 0x08 */
  __IO uint32_t APB2RSTR;   /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
  __IO uint32_t APB1RSTR;   /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHBENR;     /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
  __IO uint32_t APB2ENR;    /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
  __IO uint32_t APB1ENR;    /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
  __IO uint32_t BDCR;       /*!< RCC Backup domain control register,                          Address offset: 0x20 */ 
  __IO uint32_t CSR;        /*!< RCC clock control & status register,                         Address offset: 0x24 */
  __IO uint32_t AHBRSTR;    /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
  __IO uint32_t CFGR2;      /*!< RCC clock configuration register 2,                          Address offset: 0x2C */
  __IO uint32_t CFGR3;      /*!< RCC clock configuration register 3,                          Address offset: 0x30 */
  __IO uint32_t CR2;        /*!< RCC clock control register 2,                                Address offset: 0x34 */
} RCC_TypeDef;

/** 
  * @brief Real-Time Clock
  */

typedef struct
{                           
  __IO uint32_t TR;         /*!< RTC time register,                                        Address offset: 0x00 */
  __IO uint32_t DR;         /*!< RTC date register,                                        Address offset: 0x04 */
  __IO uint32_t CR;         /*!< RTC control register,                                     Address offset: 0x08 */
  __IO uint32_t ISR;        /*!< RTC initialization and status register,                   Address offset: 0x0C */
  __IO uint32_t PRER;       /*!< RTC prescaler register,                                   Address offset: 0x10 */
  __IO uint32_t WUTR;       /*!< RTC wakeup timer register,(only for STM32F072 devices)    Address offset: 0x14 */
       uint32_t RESERVED1;  /*!< Reserved,                                                 Address offset: 0x18 */
  __IO uint32_t ALRMAR;     /*!< RTC alarm A register,                                     Address offset: 0x1C */
       uint32_t RESERVED2;  /*!< Reserved,                                                 Address offset: 0x20 */
  __IO uint32_t WPR;        /*!< RTC write protection register,                            Address offset: 0x24 */
  __IO uint32_t SSR;        /*!< RTC sub second register,                                  Address offset: 0x28 */
  __IO uint32_t SHIFTR;     /*!< RTC shift control register,                               Address offset: 0x2C */
  __IO uint32_t TSTR;       /*!< RTC time stamp time register,                             Address offset: 0x30 */
  __IO uint32_t TSDR;       /*!< RTC time stamp date register,                             Address offset: 0x34 */
  __IO uint32_t TSSSR;      /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
  __IO uint32_t CALR;       /*!< RTC calibration register,                                 Address offset: 0x3C */
  __IO uint32_t TAFCR;      /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
  __IO uint32_t ALRMASSR;   /*!< RTC alarm A sub second register,                          Address offset: 0x44 */
       uint32_t RESERVED3;  /*!< Reserved,                                                 Address offset: 0x48 */
       uint32_t RESERVED4;  /*!< Reserved,                                                 Address offset: 0x4C */
  __IO uint32_t BKP0R;      /*!< RTC backup register 0,                                    Address offset: 0x50 */
  __IO uint32_t BKP1R;      /*!< RTC backup register 1,                                    Address offset: 0x54 */
  __IO uint32_t BKP2R;      /*!< RTC backup register 2,                                    Address offset: 0x58 */
  __IO uint32_t BKP3R;      /*!< RTC backup register 3,                                    Address offset: 0x5C */
  __IO uint32_t BKP4R;      /*!< RTC backup register 4,                                    Address offset: 0x60 */
} RTC_TypeDef;

/* Old register name definition maintained for legacy purpose */
#define CAL   CALR

/** 
  * @brief Serial Peripheral Interface
  */
  
typedef struct
{
  __IO uint16_t CR1;      /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
  uint16_t  RESERVED0;    /*!< Reserved, 0x02                                                            */
  __IO uint16_t CR2;      /*!< SPI Control register 2,                              Address offset: 0x04 */
  uint16_t  RESERVED1;    /*!< Reserved, 0x06                                                            */
  __IO uint16_t SR;       /*!< SPI Status register,                                 Address offset: 0x08 */
  uint16_t  RESERVED2;    /*!< Reserved, 0x0A                                                            */
  __IO uint16_t DR;       /*!< SPI data register,                                   Address offset: 0x0C */
  uint16_t  RESERVED3;    /*!< Reserved, 0x0E                                                            */
  __IO uint16_t CRCPR;    /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
  uint16_t  RESERVED4;    /*!< Reserved, 0x12                                                            */
  __IO uint16_t RXCRCR;   /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
  uint16_t  RESERVED5;    /*!< Reserved, 0x16                                                            */
  __IO uint16_t TXCRCR;   /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
  uint16_t  RESERVED6;    /*!< Reserved, 0x1A                                                            */ 
  __IO uint16_t I2SCFGR;  /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
  uint16_t  RESERVED7;    /*!< Reserved, 0x1E                                                            */
  __IO uint16_t I2SPR;    /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */
  uint16_t  RESERVED8;    /*!< Reserved, 0x22                                                            */    
} SPI_TypeDef;


/** 
  * @brief TIM
  */
typedef struct
{
  __IO uint16_t CR1;             /*!< TIM control register 1,                      Address offset: 0x00 */
  uint16_t      RESERVED0;       /*!< Reserved,                                                    0x02 */
  __IO uint16_t CR2;             /*!< TIM control register 2,                      Address offset: 0x04 */
  uint16_t      RESERVED1;       /*!< Reserved,                                                    0x06 */
  __IO uint16_t SMCR;            /*!< TIM slave Mode Control register,             Address offset: 0x08 */
  uint16_t      RESERVED2;       /*!< Reserved,                                                    0x0A */
  __IO uint16_t DIER;            /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
  uint16_t      RESERVED3;       /*!< Reserved,                                                    0x0E */
  __IO uint16_t SR;              /*!< TIM status register,                         Address offset: 0x10 */
  uint16_t      RESERVED4;       /*!< Reserved,                                                    0x12 */
  __IO uint16_t EGR;             /*!< TIM event generation register,               Address offset: 0x14 */
  uint16_t      RESERVED5;       /*!< Reserved,                                                    0x16 */
  __IO uint16_t CCMR1;           /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
  uint16_t      RESERVED6;       /*!< Reserved,                                                    0x1A */
  __IO uint16_t CCMR2;           /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
  uint16_t      RESERVED7;       /*!< Reserved,                                                    0x1E */
  __IO uint16_t CCER;            /*!< TIM capture/compare enable register,         Address offset: 0x20 */
  uint16_t      RESERVED8;       /*!< Reserved,                                                    0x22 */
  __IO uint32_t CNT;             /*!< TIM counter register,                        Address offset: 0x24 */
  __IO uint16_t PSC;             /*!< TIM prescaler register,                      Address offset: 0x28 */
  uint16_t      RESERVED10;      /*!< Reserved,                                                    0x2A */
  __IO uint32_t ARR;             /*!< TIM auto-reload register,                    Address offset: 0x2C */
  __IO uint16_t RCR;             /*!< TIM  repetition counter register,            Address offset: 0x30 */
  uint16_t      RESERVED12;      /*!< Reserved,                                                    0x32 */
  __IO uint32_t CCR1;            /*!< TIM capture/compare register 1,              Address offset: 0x34 */
  __IO uint32_t CCR2;            /*!< TIM capture/compare register 2,              Address offset: 0x38 */
  __IO uint32_t CCR3;            /*!< TIM capture/compare register 3,              Address offset: 0x3C */
  __IO uint32_t CCR4;            /*!< TIM capture/compare register 4,              Address offset: 0x40 */
  __IO uint16_t BDTR;            /*!< TIM break and dead-time register,            Address offset: 0x44 */
  uint16_t      RESERVED17;      /*!< Reserved,                                                    0x26 */
  __IO uint16_t DCR;             /*!< TIM DMA control register,                    Address offset: 0x48 */
  uint16_t      RESERVED18;      /*!< Reserved,                                                    0x4A */
  __IO uint16_t DMAR;            /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
  uint16_t      RESERVED19;      /*!< Reserved,                                                    0x4E */
  __IO uint16_t OR;              /*!< TIM option register,                         Address offset: 0x50 */
  uint16_t      RESERVED20;      /*!< Reserved,                                                    0x52 */
} TIM_TypeDef;

/** 
  * @brief Touch Sensing Controller (TSC)
  */
typedef struct
{
  __IO uint32_t CR;        /*!< TSC control register,                                     Address offset: 0x00 */
  __IO uint32_t IER;       /*!< TSC interrupt enable register,                            Address offset: 0x04 */
  __IO uint32_t ICR;       /*!< TSC interrupt clear register,                             Address offset: 0x08 */ 
  __IO uint32_t ISR;       /*!< TSC interrupt status register,                            Address offset: 0x0C */
  __IO uint32_t IOHCR;     /*!< TSC I/O hysteresis control register,                      Address offset: 0x10 */
  __IO uint32_t RESERVED1; /*!< Reserved,                                                 Address offset: 0x14 */
  __IO uint32_t IOASCR;    /*!< TSC I/O analog switch control register,                   Address offset: 0x18 */
  __IO uint32_t RESERVED2; /*!< Reserved,                                                 Address offset: 0x1C */
  __IO uint32_t IOSCR;     /*!< TSC I/O sampling control register,                        Address offset: 0x20 */
  __IO uint32_t RESERVED3; /*!< Reserved,                                                 Address offset: 0x24 */
  __IO uint32_t IOCCR;     /*!< TSC I/O channel control register,                         Address offset: 0x28 */
  __IO uint32_t RESERVED4; /*!< Reserved,                                                 Address offset: 0x2C */
  __IO uint32_t IOGCSR;    /*!< TSC I/O group control status register,                    Address offset: 0x30 */
  __IO uint32_t IOGXCR[8]; /*!< TSC I/O group x counter register,                         Address offset: 0x34-50 */
} TSC_TypeDef;

/** 
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
  
typedef struct
{
  __IO uint32_t CR1;    /*!< USART Control register 1,                 Address offset: 0x00 */ 
  __IO uint32_t CR2;    /*!< USART Control register 2,                 Address offset: 0x04 */ 
  __IO uint32_t CR3;    /*!< USART Control register 3,                 Address offset: 0x08 */
  __IO uint16_t BRR;    /*!< USART Baud rate register,                 Address offset: 0x0C */
  uint16_t  RESERVED1;  /*!< Reserved, 0x0E                                                 */  
  __IO uint16_t GTPR;   /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
  uint16_t  RESERVED2;  /*!< Reserved, 0x12                                                 */
  __IO uint32_t RTOR;   /*!< USART Receiver Time Out register,         Address offset: 0x14 */  
  __IO uint16_t RQR;    /*!< USART Request register,                   Address offset: 0x18 */
  uint16_t  RESERVED3;  /*!< Reserved, 0x1A                                                 */
  __IO uint32_t ISR;    /*!< USART Interrupt and status register,      Address offset: 0x1C */
  __IO uint32_t ICR;    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
  __IO uint16_t RDR;    /*!< USART Receive Data register,              Address offset: 0x24 */
  uint16_t  RESERVED4;  /*!< Reserved, 0x26                                                 */
  __IO uint16_t TDR;    /*!< USART Transmit Data register,             Address offset: 0x28 */
  uint16_t  RESERVED5;  /*!< Reserved, 0x2A                                                 */
} USART_TypeDef;


/** 
  * @brief Window WATCHDOG
  */
typedef struct
{
  __IO uint32_t CR;   /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;  /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;   /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;


/**
  * @}
  */
  
/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE            ((uint32_t)0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE             ((uint32_t)0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */

/*!< Peripheral memory map */
#define APBPERIPH_BASE        PERIPH_BASE
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000)

#define TIM2_BASE             (APBPERIPH_BASE + 0x00000000)
#define TIM3_BASE             (APBPERIPH_BASE + 0x00000400)
#define TIM6_BASE             (APBPERIPH_BASE + 0x00001000)
#define TIM7_BASE             (APBPERIPH_BASE + 0x00001400)
#define TIM14_BASE            (APBPERIPH_BASE + 0x00002000)
#define RTC_BASE              (APBPERIPH_BASE + 0x00002800)
#define WWDG_BASE             (APBPERIPH_BASE + 0x00002C00)
#define IWDG_BASE             (APBPERIPH_BASE + 0x00003000)
#define SPI2_BASE             (APBPERIPH_BASE + 0x00003800)
#define USART2_BASE           (APBPERIPH_BASE + 0x00004400)
#define USART3_BASE           (APBPERIPH_BASE + 0x00004800)
#define USART4_BASE           (APBPERIPH_BASE + 0x00004C00)
#define USART5_BASE           (APBPERIPH_BASE + 0x00005000)
#define I2C1_BASE             (APBPERIPH_BASE + 0x00005400)
#define I2C2_BASE             (APBPERIPH_BASE + 0x00005800)
#define CAN_BASE              (APBPERIPH_BASE + 0x00006400)
#define CRS_BASE              (APBPERIPH_BASE + 0x00006C00)
#define PWR_BASE              (APBPERIPH_BASE + 0x00007000)
#define DAC_BASE              (APBPERIPH_BASE + 0x00007400)
#define CEC_BASE              (APBPERIPH_BASE + 0x00007800)

#define SYSCFG_BASE           (APBPERIPH_BASE + 0x00010000)
#define COMP_BASE             (APBPERIPH_BASE + 0x0001001C)
#define EXTI_BASE             (APBPERIPH_BASE + 0x00010400)
#define USART6_BASE           (APBPERIPH_BASE + 0x00011400)
#define USART7_BASE           (APBPERIPH_BASE + 0x00011800)
#define USART8_BASE           (APBPERIPH_BASE + 0x00011C00)
#define ADC1_BASE             (APBPERIPH_BASE + 0x00012400) /* KVL: TBC*/
#define ADC_BASE              (APBPERIPH_BASE + 0x00012708) /* KVL: TBC*/
#define TIM1_BASE             (APBPERIPH_BASE + 0x00012C00)
#define SPI1_BASE             (APBPERIPH_BASE + 0x00013000)
#define USART1_BASE           (APBPERIPH_BASE + 0x00013800)
#define TIM15_BASE            (APBPERIPH_BASE + 0x00014000)
#define TIM16_BASE            (APBPERIPH_BASE + 0x00014400)
#define TIM17_BASE            (APBPERIPH_BASE + 0x00014800)
#define DBGMCU_BASE           (APBPERIPH_BASE + 0x00015800)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000)
#define DMA1_Channel1_BASE    (DMA1_BASE + 0x00000008)
#define DMA1_Channel2_BASE    (DMA1_BASE + 0x0000001C)
#define DMA1_Channel3_BASE    (DMA1_BASE + 0x00000030)
#define DMA1_Channel4_BASE    (DMA1_BASE + 0x00000044)
#define DMA1_Channel5_BASE    (DMA1_BASE + 0x00000058)
#define DMA1_Channel6_BASE    (DMA1_BASE + 0x0000006C)
#define DMA1_Channel7_BASE    (DMA1_BASE + 0x00000080)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x00000400)
#define DMA2_Channel1_BASE    (DMA2_BASE + 0x00000008)
#define DMA2_Channel2_BASE    (DMA2_BASE + 0x0000001C)
#define DMA2_Channel3_BASE    (DMA2_BASE + 0x00000030)
#define DMA2_Channel4_BASE    (DMA2_BASE + 0x00000044)
#define DMA2_Channel5_BASE    (DMA2_BASE + 0x00000058)

#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000) /*!< FLASH registers base address */
#define OB_BASE               ((uint32_t)0x1FFFF800)        /*!< FLASH Option Bytes base address */
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000)
#define TSC_BASE              (AHBPERIPH_BASE + 0x00004000)

#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x00000000)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x00000800)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x00000C00)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x00001000)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x00001400)

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */  

#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define TIM14               ((TIM_TypeDef *) TIM14_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define USART4              ((USART_TypeDef *) USART4_BASE)
#define USART5              ((USART_TypeDef *) USART5_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define CAN                 ((CAN_TypeDef *) CAN_BASE)
#define CRS                 ((CRS_TypeDef *) CRS_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define DAC                 ((DAC_TypeDef *) DAC_BASE)
#define CEC                 ((CEC_TypeDef *) CEC_BASE)

#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define COMP                ((COMP_TypeDef *) COMP_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define USART6              ((USART_TypeDef *) USART6_BASE)
#define USART7              ((USART_TypeDef *) USART7_BASE)
#define USART8              ((USART_TypeDef *) USART8_BASE)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC                 ((ADC_Common_TypeDef *) ADC_BASE)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define TIM15               ((TIM_TypeDef *) TIM15_BASE)
#define TIM16               ((TIM_TypeDef *) TIM16_BASE)
#define TIM17               ((TIM_TypeDef *) TIM17_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)

#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#define DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
#define DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
#define DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
#define DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
#define DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)

#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define OB                  ((OB_TypeDef *) OB_BASE) 
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define TSC                 ((TSC_TypeDef *) TSC_BASE)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */
  
  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */
    
/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for ADC_ISR register  ******************/
#define ADC_ISR_AWD                          ((uint32_t)0x00000080)        /*!< Analog watchdog flag */
#define ADC_ISR_OVR                          ((uint32_t)0x00000010)        /*!< Overrun flag */
#define ADC_ISR_EOSEQ                        ((uint32_t)0x00000008)        /*!< End of Sequence flag */
#define ADC_ISR_EOC                          ((uint32_t)0x00000004)        /*!< End of Conversion */
#define ADC_ISR_EOSMP                        ((uint32_t)0x00000002)        /*!< End of sampling flag */
#define ADC_ISR_ADRDY                        ((uint32_t)0x00000001)        /*!< ADC Ready */

/* Old EOSEQ bit definition, maintained for legacy purpose */
#define ADC_ISR_EOS                          ADC_ISR_EOSEQ

/********************  Bits definition for ADC_IER register  ******************/
#define ADC_IER_AWDIE                        ((uint32_t)0x00000080)        /*!< Analog Watchdog interrupt enable */
#define ADC_IER_OVRIE                        ((uint32_t)0x00000010)        /*!< Overrun interrupt enable */
#define ADC_IER_EOSEQIE                      ((uint32_t)0x00000008)        /*!< End of Sequence of conversion interrupt enable */
#define ADC_IER_EOCIE                        ((uint32_t)0x00000004)        /*!< End of Conversion interrupt enable */
#define ADC_IER_EOSMPIE                      ((uint32_t)0x00000002)        /*!< End of sampling interrupt enable */
#define ADC_IER_ADRDYIE                      ((uint32_t)0x00000001)        /*!< ADC Ready interrupt enable */

/* Old EOSEQIE bit definition, maintained for legacy purpose */
#define ADC_IER_EOSIE                        ADC_IER_EOSEQIE

/********************  Bits definition for ADC_CR register  *******************/
#define ADC_CR_ADCAL                         ((uint32_t)0x80000000)        /*!< ADC calibration */
#define ADC_CR_ADSTP                         ((uint32_t)0x00000010)        /*!< ADC stop of conversion command */
#define ADC_CR_ADSTART                       ((uint32_t)0x00000004)        /*!< ADC start of conversion */
#define ADC_CR_ADDIS                         ((uint32_t)0x00000002)        /*!< ADC disable command */
#define ADC_CR_ADEN                          ((uint32_t)0x00000001)        /*!< ADC enable control */

/*******************  Bits definition for ADC_CFGR1 register  *****************/
#define  ADC_CFGR1_AWDCH                      ((uint32_t)0x7C000000)       /*!< AWDCH[4:0] bits (Analog watchdog channel select bits) */
#define  ADC_CFGR1_AWDCH_0                    ((uint32_t)0x04000000)       /*!< Bit 0 */
#define  ADC_CFGR1_AWDCH_1                    ((uint32_t)0x08000000)       /*!< Bit 1 */
#define  ADC_CFGR1_AWDCH_2                    ((uint32_t)0x10000000)       /*!< Bit 2 */
#define  ADC_CFGR1_AWDCH_3                    ((uint32_t)0x20000000)       /*!< Bit 3 */
#define  ADC_CFGR1_AWDCH_4                    ((uint32_t)0x40000000)       /*!< Bit 4 */
#define  ADC_CFGR1_AWDEN                      ((uint32_t)0x00800000)       /*!< Analog watchdog enable on regular channels */
#define  ADC_CFGR1_AWDSGL                     ((uint32_t)0x00400000)       /*!< Enable the watchdog on a single channel or on all channels  */
#define  ADC_CFGR1_DISCEN                     ((uint32_t)0x00010000)       /*!< Discontinuous mode on regular channels */
#define  ADC_CFGR1_AUTOFF                     ((uint32_t)0x00008000)       /*!< ADC auto power off */
#define  ADC_CFGR1_WAIT                       ((uint32_t)0x00004000)       /*!< ADC wait conversion mode */
#define  ADC_CFGR1_CONT                       ((uint32_t)0x00002000)       /*!< Continuous Conversion */
#define  ADC_CFGR1_OVRMOD                     ((uint32_t)0x00001000)       /*!< Overrun mode */
#define  ADC_CFGR1_EXTEN                      ((uint32_t)0x00000C00)       /*!< EXTEN[1:0] bits (External Trigger Conversion mode for regular channels) */
#define  ADC_CFGR1_EXTEN_0                    ((uint32_t)0x00000400)       /*!< Bit 0 */
#define  ADC_CFGR1_EXTEN_1                    ((uint32_t)0x00000800)       /*!< Bit 1 */
#define  ADC_CFGR1_EXTSEL                     ((uint32_t)0x000001C0)       /*!< EXTSEL[2:0] bits (External Event Select for regular group) */
#define  ADC_CFGR1_EXTSEL_0                   ((uint32_t)0x00000040)       /*!< Bit 0 */
#define  ADC_CFGR1_EXTSEL_1                   ((uint32_t)0x00000080)       /*!< Bit 1 */
#define  ADC_CFGR1_EXTSEL_2                   ((uint32_t)0x00000100)       /*!< Bit 2 */
#define  ADC_CFGR1_ALIGN                      ((uint32_t)0x00000020)       /*!< Data Alignment */
#define  ADC_CFGR1_RES                        ((uint32_t)0x00000018)       /*!< RES[1:0] bits (Resolution) */
#define  ADC_CFGR1_RES_0                      ((uint32_t)0x00000008)       /*!< Bit 0 */
#define  ADC_CFGR1_RES_1                      ((uint32_t)0x00000010)       /*!< Bit 1 */
#define  ADC_CFGR1_SCANDIR                    ((uint32_t)0x00000004)       /*!< Sequence scan direction */
#define  ADC_CFGR1_DMACFG                     ((uint32_t)0x00000002)       /*!< Direct memory access configuration */
#define  ADC_CFGR1_DMAEN                      ((uint32_t)0x00000001)       /*!< Direct memory access enable */

/* Old WAIT bit definition, maintained for legacy purpose */
#define  ADC_CFGR1_AUTDLY                     ADC_CFGR1_WAIT

/*******************  Bits definition for ADC_CFGR2 register  *****************/
#define  ADC_CFGR2_CKMODE                     ((uint32_t)0xC0000000)       /*!< ADC clock mode */
#define  ADC_CFGR2_CKMODE_1                   ((uint32_t)0x80000000)       /*!< ADC clocked by PCLK div4 */
#define  ADC_CFGR2_CKMODE_0                   ((uint32_t)0x40000000)       /*!< ADC clocked by PCLK div2 */

/* Old bit definition, maintained for legacy purpose */
#define  ADC_CFGR2_JITOFFDIV4                 ADC_CFGR2_CKMODE_1           /*!< ADC clocked by PCLK div4 */
#define  ADC_CFGR2_JITOFFDIV2                 ADC_CFGR2_CKMODE_0           /*!< ADC clocked by PCLK div2 */

/******************  Bit definition for ADC_SMPR register  ********************/
#define  ADC_SMPR_SMP                      ((uint32_t)0x00000007)        /*!< SMP[2:0] bits (Sampling time selection) */
#define  ADC_SMPR_SMP_0                    ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  ADC_SMPR_SMP_1                    ((uint32_t)0x00000002)        /*!< Bit 1 */
#define  ADC_SMPR_SMP_2                    ((uint32_t)0x00000004)        /*!< Bit 2 */

/* Old bit definition, maintained for legacy purpose */
#define  ADC_SMPR1_SMPR                      ADC_SMPR_SMP        /*!< SMP[2:0] bits (Sampling time selection) */
#define  ADC_SMPR1_SMPR_0                    ADC_SMPR_SMP_0        /*!< Bit 0 */
#define  ADC_SMPR1_SMPR_1                    ADC_SMPR_SMP_1        /*!< Bit 1 */
#define  ADC_SMPR1_SMPR_2                    ADC_SMPR_SMP_2        /*!< Bit 2 */

/*******************  Bit definition for ADC_TR register  ********************/
#define  ADC_TR_HT                          ((uint32_t)0x0FFF0000)        /*!< Analog watchdog high threshold */
#define  ADC_TR_LT                          ((uint32_t)0x00000FFF)        /*!< Analog watchdog low threshold */

/* Old bit definition, maintained for legacy purpose */
#define  ADC_HTR_HT                          ADC_TR_HT                    /*!< Analog watchdog high threshold */
#define  ADC_LTR_LT                          ADC_TR_LT                    /*!< Analog watchdog low threshold */

/******************  Bit definition for ADC_CHSELR register  ******************/
#define  ADC_CHSELR_CHSEL18                   ((uint32_t)0x00040000)        /*!< Channel 18 selection */
#define  ADC_CHSELR_CHSEL17                   ((uint32_t)0x00020000)        /*!< Channel 17 selection */
#define  ADC_CHSELR_CHSEL16                   ((uint32_t)0x00010000)        /*!< Channel 16 selection */
#define  ADC_CHSELR_CHSEL15                   ((uint32_t)0x00008000)        /*!< Channel 15 selection */
#define  ADC_CHSELR_CHSEL14                   ((uint32_t)0x00004000)        /*!< Channel 14 selection */
#define  ADC_CHSELR_CHSEL13                   ((uint32_t)0x00002000)        /*!< Channel 13 selection */
#define  ADC_CHSELR_CHSEL12                   ((uint32_t)0x00001000)        /*!< Channel 12 selection */
#define  ADC_CHSELR_CHSEL11                   ((uint32_t)0x00000800)        /*!< Channel 11 selection */
#define  ADC_CHSELR_CHSEL10                   ((uint32_t)0x00000400)        /*!< Channel 10 selection */
#define  ADC_CHSELR_CHSEL9                    ((uint32_t)0x00000200)        /*!< Channel 9 selection */
#define  ADC_CHSELR_CHSEL8                    ((uint32_t)0x00000100)        /*!< Channel 8 selection */
#define  ADC_CHSELR_CHSEL7                    ((uint32_t)0x00000080)        /*!< Channel 7 selection */
#define  ADC_CHSELR_CHSEL6                    ((uint32_t)0x00000040)        /*!< Channel 6 selection */
#define  ADC_CHSELR_CHSEL5                    ((uint32_t)0x00000020)        /*!< Channel 5 selection */
#define  ADC_CHSELR_CHSEL4                    ((uint32_t)0x00000010)        /*!< Channel 4 selection */
#define  ADC_CHSELR_CHSEL3                    ((uint32_t)0x00000008)        /*!< Channel 3 selection */
#define  ADC_CHSELR_CHSEL2                    ((uint32_t)0x00000004)        /*!< Channel 2 selection */
#define  ADC_CHSELR_CHSEL1                    ((uint32_t)0x00000002)        /*!< Channel 1 selection */
#define  ADC_CHSELR_CHSEL0                    ((uint32_t)0x00000001)        /*!< Channel 0 selection */

/********************  Bit definition for ADC_DR register  ********************/
#define  ADC_DR_DATA                         ((uint32_t)0x0000FFFF)        /*!< Regular data */

/*******************  Bit definition for ADC_CCR register  ********************/
#define  ADC_CCR_VBATEN                       ((uint32_t)0x01000000)       /*!< Voltage battery enable */
#define  ADC_CCR_TSEN                         ((uint32_t)0x00800000)       /*!< Tempurature sensore enable */
#define  ADC_CCR_VREFEN                       ((uint32_t)0x00400000)       /*!< Vrefint enable */

/******************************************************************************/
/*                                                                            */
/*                   Controller Area Network (CAN )                           */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CAN_MCR register  ********************/
#define  CAN_MCR_INRQ                        ((uint16_t)0x0001)            /*!<Initialization Request */
#define  CAN_MCR_SLEEP                       ((uint16_t)0x0002)            /*!<Sleep Mode Request */
#define  CAN_MCR_TXFP                        ((uint16_t)0x0004)            /*!<Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        ((uint16_t)0x0008)            /*!<Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        ((uint16_t)0x0010)            /*!<No Automatic Retransmission */
#define  CAN_MCR_AWUM                        ((uint16_t)0x0020)            /*!<Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        ((uint16_t)0x0040)            /*!<Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        ((uint16_t)0x0080)            /*!<Time Triggered Communication Mode */
#define  CAN_MCR_RESET                       ((uint16_t)0x8000)            /*!<bxCAN software master reset */

/*******************  Bit definition for CAN_MSR register  ********************/
#define  CAN_MSR_INAK                        ((uint16_t)0x0001)            /*!<Initialization Acknowledge */
#define  CAN_MSR_SLAK                        ((uint16_t)0x0002)            /*!<Sleep Acknowledge */
#define  CAN_MSR_ERRI                        ((uint16_t)0x0004)            /*!<Error Interrupt */
#define  CAN_MSR_WKUI                        ((uint16_t)0x0008)            /*!<Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       ((uint16_t)0x0010)            /*!<Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         ((uint16_t)0x0100)            /*!<Transmit Mode */
#define  CAN_MSR_RXM                         ((uint16_t)0x0200)            /*!<Receive Mode */
#define  CAN_MSR_SAMP                        ((uint16_t)0x0400)            /*!<Last Sample Point */
#define  CAN_MSR_RX                          ((uint16_t)0x0800)            /*!<CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define  CAN_TSR_RQCP0                       ((uint32_t)0x00000001)        /*!<Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       ((uint32_t)0x00000002)        /*!<Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       ((uint32_t)0x00000004)        /*!<Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       ((uint32_t)0x00000008)        /*!<Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       ((uint32_t)0x00000080)        /*!<Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       ((uint32_t)0x00000100)        /*!<Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       ((uint32_t)0x00000200)        /*!<Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       ((uint32_t)0x00000400)        /*!<Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       ((uint32_t)0x00000800)        /*!<Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       ((uint32_t)0x00008000)        /*!<Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       ((uint32_t)0x00010000)        /*!<Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       ((uint32_t)0x00020000)        /*!<Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       ((uint32_t)0x00040000)        /*!<Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       ((uint32_t)0x00080000)        /*!<Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       ((uint32_t)0x00800000)        /*!<Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        ((uint32_t)0x03000000)        /*!<Mailbox Code */

#define  CAN_TSR_TME                         ((uint32_t)0x1C000000)        /*!<TME[2:0] bits */
#define  CAN_TSR_TME0                        ((uint32_t)0x04000000)        /*!<Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        ((uint32_t)0x08000000)        /*!<Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        ((uint32_t)0x10000000)        /*!<Transmit Mailbox 2 Empty */

#define  CAN_TSR_LOW                         ((uint32_t)0xE0000000)        /*!<LOW[2:0] bits */
#define  CAN_TSR_LOW0                        ((uint32_t)0x20000000)        /*!<Lowest Priority Flag for Mailbox 0 */
#define  CAN_TSR_LOW1                        ((uint32_t)0x40000000)        /*!<Lowest Priority Flag for Mailbox 1 */
#define  CAN_TSR_LOW2                        ((uint32_t)0x80000000)        /*!<Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define  CAN_RF0R_FMP0                       ((uint8_t)0x03)               /*!<FIFO 0 Message Pending */
#define  CAN_RF0R_FULL0                      ((uint8_t)0x08)               /*!<FIFO 0 Full */
#define  CAN_RF0R_FOVR0                      ((uint8_t)0x10)               /*!<FIFO 0 Overrun */
#define  CAN_RF0R_RFOM0                      ((uint8_t)0x20)               /*!<Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define  CAN_RF1R_FMP1                       ((uint8_t)0x03)               /*!<FIFO 1 Message Pending */
#define  CAN_RF1R_FULL1                      ((uint8_t)0x08)               /*!<FIFO 1 Full */
#define  CAN_RF1R_FOVR1                      ((uint8_t)0x10)               /*!<FIFO 1 Overrun */
#define  CAN_RF1R_RFOM1                      ((uint8_t)0x20)               /*!<Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define  CAN_IER_TMEIE                       ((uint32_t)0x00000001)        /*!<Transmit Mailbox Empty Interrupt Enable */
#define  CAN_IER_FMPIE0                      ((uint32_t)0x00000002)        /*!<FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE0                       ((uint32_t)0x00000004)        /*!<FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE0                      ((uint32_t)0x00000008)        /*!<FIFO Overrun Interrupt Enable */
#define  CAN_IER_FMPIE1                      ((uint32_t)0x00000010)        /*!<FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE1                       ((uint32_t)0x00000020)        /*!<FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE1                      ((uint32_t)0x00000040)        /*!<FIFO Overrun Interrupt Enable */
#define  CAN_IER_EWGIE                       ((uint32_t)0x00000100)        /*!<Error Warning Interrupt Enable */
#define  CAN_IER_EPVIE                       ((uint32_t)0x00000200)        /*!<Error Passive Interrupt Enable */
#define  CAN_IER_BOFIE                       ((uint32_t)0x00000400)        /*!<Bus-Off Interrupt Enable */
#define  CAN_IER_LECIE                       ((uint32_t)0x00000800)        /*!<Last Error Code Interrupt Enable */
#define  CAN_IER_ERRIE                       ((uint32_t)0x00008000)        /*!<Error Interrupt Enable */
#define  CAN_IER_WKUIE                       ((uint32_t)0x00010000)        /*!<Wakeup Interrupt Enable */
#define  CAN_IER_SLKIE                       ((uint32_t)0x00020000)        /*!<Sleep Interrupt Enable */

/********************  Bit definition for CAN_ESR register  *******************/
#define  CAN_ESR_EWGF                        ((uint32_t)0x00000001)        /*!<Error Warning Flag */
#define  CAN_ESR_EPVF                        ((uint32_t)0x00000002)        /*!<Error Passive Flag */
#define  CAN_ESR_BOFF                        ((uint32_t)0x00000004)        /*!<Bus-Off Flag */

#define  CAN_ESR_LEC                         ((uint32_t)0x00000070)        /*!<LEC[2:0] bits (Last Error Code) */
#define  CAN_ESR_LEC_0                       ((uint32_t)0x00000010)        /*!<Bit 0 */
#define  CAN_ESR_LEC_1                       ((uint32_t)0x00000020)        /*!<Bit 1 */
#define  CAN_ESR_LEC_2                       ((uint32_t)0x00000040)        /*!<Bit 2 */

#define  CAN_ESR_TEC                         ((uint32_t)0x00FF0000)        /*!<Least significant byte of the 9-bit Transmit Error Counter */
#define  CAN_ESR_REC                         ((uint32_t)0xFF000000)        /*!<Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define  CAN_BTR_BRP                         ((uint32_t)0x000003FF)        /*!<Baud Rate Prescaler */
#define  CAN_BTR_TS1                         ((uint32_t)0x000F0000)        /*!<Time Segment 1 */
#define  CAN_BTR_TS2                         ((uint32_t)0x00700000)        /*!<Time Segment 2 */
#define  CAN_BTR_SJW                         ((uint32_t)0x03000000)        /*!<Resynchronization Jump Width */
#define  CAN_BTR_LBKM                        ((uint32_t)0x40000000)        /*!<Loop Back Mode (Debug) */
#define  CAN_BTR_SILM                        ((uint32_t)0x80000000)        /*!<Silent Mode */

/*!<Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define  CAN_TI0R_TXRQ                       ((uint32_t)0x00000001)        /*!<Transmit Mailbox Request */
#define  CAN_TI0R_RTR                        ((uint32_t)0x00000002)        /*!<Remote Transmission Request */
#define  CAN_TI0R_IDE                        ((uint32_t)0x00000004)        /*!<Identifier Extension */
#define  CAN_TI0R_EXID                       ((uint32_t)0x001FFFF8)        /*!<Extended Identifier */
#define  CAN_TI0R_STID                       ((uint32_t)0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define  CAN_TDT0R_DLC                       ((uint32_t)0x0000000F)        /*!<Data Length Code */
#define  CAN_TDT0R_TGT                       ((uint32_t)0x00000100)        /*!<Transmit Global Time */
#define  CAN_TDT0R_TIME                      ((uint32_t)0xFFFF0000)        /*!<Message Time Stamp */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define  CAN_TDL0R_DATA0                     ((uint32_t)0x000000FF)        /*!<Data byte 0 */
#define  CAN_TDL0R_DATA1                     ((uint32_t)0x0000FF00)        /*!<Data byte 1 */
#define  CAN_TDL0R_DATA2                     ((uint32_t)0x00FF0000)        /*!<Data byte 2 */
#define  CAN_TDL0R_DATA3                     ((uint32_t)0xFF000000)        /*!<Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define  CAN_TDH0R_DATA4                     ((uint32_t)0x000000FF)        /*!<Data byte 4 */
#define  CAN_TDH0R_DATA5                     ((uint32_t)0x0000FF00)        /*!<Data byte 5 */
#define  CAN_TDH0R_DATA6                     ((uint32_t)0x00FF0000)        /*!<Data byte 6 */
#define  CAN_TDH0R_DATA7                     ((uint32_t)0xFF000000)        /*!<Data byte 7 */

/*******************  Bit definition for CAN_TI1R register  *******************/
#define  CAN_TI1R_TXRQ                       ((uint32_t)0x00000001)        /*!<Transmit Mailbox Request */
#define  CAN_TI1R_RTR                        ((uint32_t)0x00000002)        /*!<Remote Transmission Request */
#define  CAN_TI1R_IDE                        ((uint32_t)0x00000004)        /*!<Identifier Extension */
#define  CAN_TI1R_EXID                       ((uint32_t)0x001FFFF8)        /*!<Extended Identifier */
#define  CAN_TI1R_STID                       ((uint32_t)0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define  CAN_TDT1R_DLC                       ((uint32_t)0x0000000F)        /*!<Data Length Code */
#define  CAN_TDT1R_TGT                       ((uint32_t)0x00000100)        /*!<Transmit Global Time */
#define  CAN_TDT1R_TIME                      ((uint32_t)0xFFFF0000)        /*!<Message Time Stamp */

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define  CAN_TDL1R_DATA0                     ((uint32_t)0x000000FF)        /*!<Data byte 0 */
#define  CAN_TDL1R_DATA1                     ((uint32_t)0x0000FF00)        /*!<Data byte 1 */
#define  CAN_TDL1R_DATA2                     ((uint32_t)0x00FF0000)        /*!<Data byte 2 */
#define  CAN_TDL1R_DATA3                     ((uint32_t)0xFF000000)        /*!<Data byte 3 */

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define  CAN_TDH1R_DATA4                     ((uint32_t)0x000000FF)        /*!<Data byte 4 */
#define  CAN_TDH1R_DATA5                     ((uint32_t)0x0000FF00)        /*!<Data byte 5 */
#define  CAN_TDH1R_DATA6                     ((uint32_t)0x00FF0000)        /*!<Data byte 6 */
#define  CAN_TDH1R_DATA7                     ((uint32_t)0xFF000000)        /*!<Data byte 7 */

/*******************  Bit definition for CAN_TI2R register  *******************/
#define  CAN_TI2R_TXRQ                       ((uint32_t)0x00000001)        /*!<Transmit Mailbox Request */
#define  CAN_TI2R_RTR                        ((uint32_t)0x00000002)        /*!<Remote Transmission Request */
#define  CAN_TI2R_IDE                        ((uint32_t)0x00000004)        /*!<Identifier Extension */
#define  CAN_TI2R_EXID                       ((uint32_t)0x001FFFF8)        /*!<Extended identifier */
#define  CAN_TI2R_STID                       ((uint32_t)0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT2R register  ******************/  
#define  CAN_TDT2R_DLC                       ((uint32_t)0x0000000F)        /*!<Data Length Code */
#define  CAN_TDT2R_TGT                       ((uint32_t)0x00000100)        /*!<Transmit Global Time */
#define  CAN_TDT2R_TIME                      ((uint32_t)0xFFFF0000)        /*!<Message Time Stamp */

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define  CAN_TDL2R_DATA0                     ((uint32_t)0x000000FF)        /*!<Data byte 0 */
#define  CAN_TDL2R_DATA1                     ((uint32_t)0x0000FF00)        /*!<Data byte 1 */
#define  CAN_TDL2R_DATA2                     ((uint32_t)0x00FF0000)        /*!<Data byte 2 */
#define  CAN_TDL2R_DATA3                     ((uint32_t)0xFF000000)        /*!<Data byte 3 */

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define  CAN_TDH2R_DATA4                     ((uint32_t)0x000000FF)        /*!<Data byte 4 */
#define  CAN_TDH2R_DATA5                     ((uint32_t)0x0000FF00)        /*!<Data byte 5 */
#define  CAN_TDH2R_DATA6                     ((uint32_t)0x00FF0000)        /*!<Data byte 6 */
#define  CAN_TDH2R_DATA7                     ((uint32_t)0xFF000000)        /*!<Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define  CAN_RI0R_RTR                        ((uint32_t)0x00000002)        /*!<Remote Transmission Request */
#define  CAN_RI0R_IDE                        ((uint32_t)0x00000004)        /*!<Identifier Extension */
#define  CAN_RI0R_EXID                       ((uint32_t)0x001FFFF8)        /*!<Extended Identifier */
#define  CAN_RI0R_STID                       ((uint32_t)0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define  CAN_RDT0R_DLC                       ((uint32_t)0x0000000F)        /*!<Data Length Code */
#define  CAN_RDT0R_FMI                       ((uint32_t)0x0000FF00)        /*!<Filter Match Index */
#define  CAN_RDT0R_TIME                      ((uint32_t)0xFFFF0000)        /*!<Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define  CAN_RDL0R_DATA0                     ((uint32_t)0x000000FF)        /*!<Data byte 0 */
#define  CAN_RDL0R_DATA1                     ((uint32_t)0x0000FF00)        /*!<Data byte 1 */
#define  CAN_RDL0R_DATA2                     ((uint32_t)0x00FF0000)        /*!<Data byte 2 */
#define  CAN_RDL0R_DATA3                     ((uint32_t)0xFF000000)        /*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define  CAN_RDH0R_DATA4                     ((uint32_t)0x000000FF)        /*!<Data byte 4 */
#define  CAN_RDH0R_DATA5                     ((uint32_t)0x0000FF00)        /*!<Data byte 5 */
#define  CAN_RDH0R_DATA6                     ((uint32_t)0x00FF0000)        /*!<Data byte 6 */
#define  CAN_RDH0R_DATA7                     ((uint32_t)0xFF000000)        /*!<Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define  CAN_RI1R_RTR                        ((uint32_t)0x00000002)        /*!<Remote Transmission Request */
#define  CAN_RI1R_IDE                        ((uint32_t)0x00000004)        /*!<Identifier Extension */
#define  CAN_RI1R_EXID                       ((uint32_t)0x001FFFF8)        /*!<Extended identifier */
#define  CAN_RI1R_STID                       ((uint32_t)0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define  CAN_RDT1R_DLC                       ((uint32_t)0x0000000F)        /*!<Data Length Code */
#define  CAN_RDT1R_FMI                       ((uint32_t)0x0000FF00)        /*!<Filter Match Index */
#define  CAN_RDT1R_TIME                      ((uint32_t)0xFFFF0000)        /*!<Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define  CAN_RDL1R_DATA0                     ((uint32_t)0x000000FF)        /*!<Data byte 0 */
#define  CAN_RDL1R_DATA1                     ((uint32_t)0x0000FF00)        /*!<Data byte 1 */
#define  CAN_RDL1R_DATA2                     ((uint32_t)0x00FF0000)        /*!<Data byte 2 */
#define  CAN_RDL1R_DATA3                     ((uint32_t)0xFF000000)        /*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define  CAN_RDH1R_DATA4                     ((uint32_t)0x000000FF)        /*!<Data byte 4 */
#define  CAN_RDH1R_DATA5                     ((uint32_t)0x0000FF00)        /*!<Data byte 5 */
#define  CAN_RDH1R_DATA6                     ((uint32_t)0x00FF0000)        /*!<Data byte 6 */
#define  CAN_RDH1R_DATA7                     ((uint32_t)0xFF000000)        /*!<Data byte 7 */

/*!<CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define  CAN_FMR_FINIT                       ((uint8_t)0x01)               /*!<Filter Init Mode */

/*******************  Bit definition for CAN_FM1R register  *******************/
#define  CAN_FM1R_FBM                        ((uint16_t)0x3FFF)            /*!<Filter Mode */
#define  CAN_FM1R_FBM0                       ((uint16_t)0x0001)            /*!<Filter Init Mode bit 0 */
#define  CAN_FM1R_FBM1                       ((uint16_t)0x0002)            /*!<Filter Init Mode bit 1 */
#define  CAN_FM1R_FBM2                       ((uint16_t)0x0004)            /*!<Filter Init Mode bit 2 */
#define  CAN_FM1R_FBM3                       ((uint16_t)0x0008)            /*!<Filter Init Mode bit 3 */
#define  CAN_FM1R_FBM4                       ((uint16_t)0x0010)            /*!<Filter Init Mode bit 4 */
#define  CAN_FM1R_FBM5                       ((uint16_t)0x0020)            /*!<Filter Init Mode bit 5 */
#define  CAN_FM1R_FBM6                       ((uint16_t)0x0040)            /*!<Filter Init Mode bit 6 */
#define  CAN_FM1R_FBM7                       ((uint16_t)0x0080)            /*!<Filter Init Mode bit 7 */
#define  CAN_FM1R_FBM8                       ((uint16_t)0x0100)            /*!<Filter Init Mode bit 8 */
#define  CAN_FM1R_FBM9                       ((uint16_t)0x0200)            /*!<Filter Init Mode bit 9 */
#define  CAN_FM1R_FBM10                      ((uint16_t)0x0400)            /*!<Filter Init Mode bit 10 */
#define  CAN_FM1R_FBM11                      ((uint16_t)0x0800)            /*!<Filter Init Mode bit 11 */
#define  CAN_FM1R_FBM12                      ((uint16_t)0x1000)            /*!<Filter Init Mode bit 12 */
#define  CAN_FM1R_FBM13                      ((uint16_t)0x2000)            /*!<Filter Init Mode bit 13 */

/*******************  Bit definition for CAN_FS1R register  *******************/
#define  CAN_FS1R_FSC                        ((uint16_t)0x3FFF)            /*!<Filter Scale Configuration */
#define  CAN_FS1R_FSC0                       ((uint16_t)0x0001)            /*!<Filter Scale Configuration bit 0 */
#define  CAN_FS1R_FSC1                       ((uint16_t)0x0002)            /*!<Filter Scale Configuration bit 1 */
#define  CAN_FS1R_FSC2                       ((uint16_t)0x0004)            /*!<Filter Scale Configuration bit 2 */
#define  CAN_FS1R_FSC3                       ((uint16_t)0x0008)            /*!<Filter Scale Configuration bit 3 */
#define  CAN_FS1R_FSC4                       ((uint16_t)0x0010)            /*!<Filter Scale Configuration bit 4 */
#define  CAN_FS1R_FSC5                       ((uint16_t)0x0020)            /*!<Filter Scale Configuration bit 5 */
#define  CAN_FS1R_FSC6                       ((uint16_t)0x0040)            /*!<Filter Scale Configuration bit 6 */
#define  CAN_FS1R_FSC7                       ((uint16_t)0x0080)            /*!<Filter Scale Configuration bit 7 */
#define  CAN_FS1R_FSC8                       ((uint16_t)0x0100)            /*!<Filter Scale Configuration bit 8 */
#define  CAN_FS1R_FSC9                       ((uint16_t)0x0200)            /*!<Filter Scale Configuration bit 9 */
#define  CAN_FS1R_FSC10                      ((uint16_t)0x0400)            /*!<Filter Scale Configuration bit 10 */
#define  CAN_FS1R_FSC11                      ((uint16_t)0x0800)            /*!<Filter Scale Configuration bit 11 */
#define  CAN_FS1R_FSC12                      ((uint16_t)0x1000)            /*!<Filter Scale Configuration bit 12 */
#define  CAN_FS1R_FSC13                      ((uint16_t)0x2000)            /*!<Filter Scale Configuration bit 13 */

/******************  Bit definition for CAN_FFA1R register  *******************/
#define  CAN_FFA1R_FFA                       ((uint16_t)0x3FFF)            /*!<Filter FIFO Assignment */
#define  CAN_FFA1R_FFA0                      ((uint16_t)0x0001)            /*!<Filter FIFO Assignment for Filter 0 */
#define  CAN_FFA1R_FFA1                      ((uint16_t)0x0002)            /*!<Filter FIFO Assignment for Filter 1 */
#define  CAN_FFA1R_FFA2                      ((uint16_t)0x0004)            /*!<Filter FIFO Assignment for Filter 2 */
#define  CAN_FFA1R_FFA3                      ((uint16_t)0x0008)            /*!<Filter FIFO Assignment for Filter 3 */
#define  CAN_FFA1R_FFA4                      ((uint16_t)0x0010)            /*!<Filter FIFO Assignment for Filter 4 */
#define  CAN_FFA1R_FFA5                      ((uint16_t)0x0020)            /*!<Filter FIFO Assignment for Filter 5 */
#define  CAN_FFA1R_FFA6                      ((uint16_t)0x0040)            /*!<Filter FIFO Assignment for Filter 6 */
#define  CAN_FFA1R_FFA7                      ((uint16_t)0x0080)            /*!<Filter FIFO Assignment for Filter 7 */
#define  CAN_FFA1R_FFA8                      ((uint16_t)0x0100)            /*!<Filter FIFO Assignment for Filter 8 */
#define  CAN_FFA1R_FFA9                      ((uint16_t)0x0200)            /*!<Filter FIFO Assignment for Filter 9 */
#define  CAN_FFA1R_FFA10                     ((uint16_t)0x0400)            /*!<Filter FIFO Assignment for Filter 10 */
#define  CAN_FFA1R_FFA11                     ((uint16_t)0x0800)            /*!<Filter FIFO Assignment for Filter 11 */
#define  CAN_FFA1R_FFA12                     ((uint16_t)0x1000)            /*!<Filter FIFO Assignment for Filter 12 */
#define  CAN_FFA1R_FFA13                     ((uint16_t)0x2000)            /*!<Filter FIFO Assignment for Filter 13 */

/*******************  Bit definition for CAN_FA1R register  *******************/
#define  CAN_FA1R_FACT                       ((uint16_t)0x3FFF)            /*!<Filter Active */
#define  CAN_FA1R_FACT0                      ((uint16_t)0x0001)            /*!<Filter 0 Active */
#define  CAN_FA1R_FACT1                      ((uint16_t)0x0002)            /*!<Filter 1 Active */
#define  CAN_FA1R_FACT2                      ((uint16_t)0x0004)            /*!<Filter 2 Active */
#define  CAN_FA1R_FACT3                      ((uint16_t)0x0008)            /*!<Filter 3 Active */
#define  CAN_FA1R_FACT4                      ((uint16_t)0x0010)            /*!<Filter 4 Active */
#define  CAN_FA1R_FACT5                      ((uint16_t)0x0020)            /*!<Filter 5 Active */
#define  CAN_FA1R_FACT6                      ((uint16_t)0x0040)            /*!<Filter 6 Active */
#define  CAN_FA1R_FACT7                      ((uint16_t)0x0080)            /*!<Filter 7 Active */
#define  CAN_FA1R_FACT8                      ((uint16_t)0x0100)            /*!<Filter 8 Active */
#define  CAN_FA1R_FACT9                      ((uint16_t)0x0200)            /*!<Filter 9 Active */
#define  CAN_FA1R_FACT10                     ((uint16_t)0x0400)            /*!<Filter 10 Active */
#define  CAN_FA1R_FACT11                     ((uint16_t)0x0800)            /*!<Filter 11 Active */
#define  CAN_FA1R_FACT12                     ((uint16_t)0x1000)            /*!<Filter 12 Active */
#define  CAN_FA1R_FACT13                     ((uint16_t)0x2000)            /*!<Filter 13 Active */

/*******************  Bit definition for CAN_F0R1 register  *******************/
#define  CAN_F0R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F0R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F0R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F0R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F0R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F0R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F0R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F0R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F0R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F0R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F0R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F0R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F0R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F0R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F0R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F0R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F0R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F0R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F0R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F0R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F0R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F0R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F0R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F0R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F0R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F0R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F0R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F0R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F0R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F0R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F0R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F0R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define  CAN_F1R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F1R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F1R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F1R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F1R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F1R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F1R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F1R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F1R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F1R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F1R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F1R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F1R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F1R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F1R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F1R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F1R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F1R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F1R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F1R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F1R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F1R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F1R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F1R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F1R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F1R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F1R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F1R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F1R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F1R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F1R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F1R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define  CAN_F2R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F2R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F2R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F2R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F2R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F2R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F2R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F2R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F2R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F2R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F2R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F2R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F2R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F2R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F2R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F2R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F2R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F2R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F2R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F2R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F2R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F2R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F2R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F2R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F2R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F2R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F2R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F2R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F2R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F2R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F2R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F2R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define  CAN_F3R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F3R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F3R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F3R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F3R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F3R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F3R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F3R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F3R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F3R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F3R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F3R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F3R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F3R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F3R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F3R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F3R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F3R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F3R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F3R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F3R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F3R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F3R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F3R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F3R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F3R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F3R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F3R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F3R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F3R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F3R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F3R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define  CAN_F4R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F4R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F4R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F4R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F4R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F4R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F4R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F4R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F4R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F4R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F4R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F4R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F4R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F4R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F4R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F4R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F4R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F4R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F4R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F4R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F4R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F4R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F4R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F4R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F4R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F4R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F4R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F4R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F4R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F4R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F4R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F4R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define  CAN_F5R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F5R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F5R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F5R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F5R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F5R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F5R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F5R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F5R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F5R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F5R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F5R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F5R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F5R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F5R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F5R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F5R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F5R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F5R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F5R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F5R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F5R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F5R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F5R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F5R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F5R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F5R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F5R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F5R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F5R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F5R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F5R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define  CAN_F6R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F6R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F6R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F6R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F6R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F6R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F6R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F6R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F6R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F6R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F6R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F6R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F6R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F6R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F6R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F6R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F6R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F6R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F6R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F6R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F6R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F6R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F6R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F6R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F6R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F6R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F6R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F6R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F6R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F6R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F6R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F6R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define  CAN_F7R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F7R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F7R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F7R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F7R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F7R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F7R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F7R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F7R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F7R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F7R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F7R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F7R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F7R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F7R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F7R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F7R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F7R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F7R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F7R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F7R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F7R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F7R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F7R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F7R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F7R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F7R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F7R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F7R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F7R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F7R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F7R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define  CAN_F8R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F8R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F8R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F8R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F8R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F8R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F8R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F8R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F8R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F8R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F8R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F8R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F8R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F8R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F8R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F8R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F8R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F8R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F8R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F8R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F8R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F8R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F8R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F8R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F8R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F8R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F8R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F8R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F8R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F8R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F8R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F8R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define  CAN_F9R1_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F9R1_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F9R1_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F9R1_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F9R1_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F9R1_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F9R1_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F9R1_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F9R1_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F9R1_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F9R1_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F9R1_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F9R1_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F9R1_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F9R1_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F9R1_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F9R1_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F9R1_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F9R1_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F9R1_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F9R1_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F9R1_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F9R1_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F9R1_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F9R1_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F9R1_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F9R1_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F9R1_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F9R1_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F9R1_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F9R1_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F9R1_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define  CAN_F10R1_FB0                       ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F10R1_FB1                       ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F10R1_FB2                       ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F10R1_FB3                       ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F10R1_FB4                       ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F10R1_FB5                       ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F10R1_FB6                       ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F10R1_FB7                       ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F10R1_FB8                       ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F10R1_FB9                       ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F10R1_FB10                      ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F10R1_FB11                      ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F10R1_FB12                      ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F10R1_FB13                      ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F10R1_FB14                      ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F10R1_FB15                      ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F10R1_FB16                      ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F10R1_FB17                      ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F10R1_FB18                      ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F10R1_FB19                      ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F10R1_FB20                      ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F10R1_FB21                      ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F10R1_FB22                      ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F10R1_FB23                      ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F10R1_FB24                      ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F10R1_FB25                      ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F10R1_FB26                      ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F10R1_FB27                      ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F10R1_FB28                      ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F10R1_FB29                      ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F10R1_FB30                      ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F10R1_FB31                      ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define  CAN_F11R1_FB0                       ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F11R1_FB1                       ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F11R1_FB2                       ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F11R1_FB3                       ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F11R1_FB4                       ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F11R1_FB5                       ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F11R1_FB6                       ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F11R1_FB7                       ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F11R1_FB8                       ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F11R1_FB9                       ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F11R1_FB10                      ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F11R1_FB11                      ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F11R1_FB12                      ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F11R1_FB13                      ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F11R1_FB14                      ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F11R1_FB15                      ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F11R1_FB16                      ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F11R1_FB17                      ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F11R1_FB18                      ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F11R1_FB19                      ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F11R1_FB20                      ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F11R1_FB21                      ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F11R1_FB22                      ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F11R1_FB23                      ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F11R1_FB24                      ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F11R1_FB25                      ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F11R1_FB26                      ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F11R1_FB27                      ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F11R1_FB28                      ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F11R1_FB29                      ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F11R1_FB30                      ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F11R1_FB31                      ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define  CAN_F12R1_FB0                       ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F12R1_FB1                       ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F12R1_FB2                       ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F12R1_FB3                       ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F12R1_FB4                       ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F12R1_FB5                       ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F12R1_FB6                       ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F12R1_FB7                       ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F12R1_FB8                       ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F12R1_FB9                       ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F12R1_FB10                      ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F12R1_FB11                      ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F12R1_FB12                      ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F12R1_FB13                      ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F12R1_FB14                      ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F12R1_FB15                      ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F12R1_FB16                      ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F12R1_FB17                      ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F12R1_FB18                      ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F12R1_FB19                      ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F12R1_FB20                      ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F12R1_FB21                      ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F12R1_FB22                      ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F12R1_FB23                      ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F12R1_FB24                      ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F12R1_FB25                      ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F12R1_FB26                      ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F12R1_FB27                      ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F12R1_FB28                      ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F12R1_FB29                      ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F12R1_FB30                      ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F12R1_FB31                      ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define  CAN_F13R1_FB0                       ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F13R1_FB1                       ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F13R1_FB2                       ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F13R1_FB3                       ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F13R1_FB4                       ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F13R1_FB5                       ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F13R1_FB6                       ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F13R1_FB7                       ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F13R1_FB8                       ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F13R1_FB9                       ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F13R1_FB10                      ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F13R1_FB11                      ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F13R1_FB12                      ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F13R1_FB13                      ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F13R1_FB14                      ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F13R1_FB15                      ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F13R1_FB16                      ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F13R1_FB17                      ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F13R1_FB18                      ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F13R1_FB19                      ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F13R1_FB20                      ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F13R1_FB21                      ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F13R1_FB22                      ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F13R1_FB23                      ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F13R1_FB24                      ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F13R1_FB25                      ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F13R1_FB26                      ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F13R1_FB27                      ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F13R1_FB28                      ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F13R1_FB29                      ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F13R1_FB30                      ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F13R1_FB31                      ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define  CAN_F0R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F0R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F0R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F0R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F0R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F0R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F0R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F0R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F0R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F0R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F0R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F0R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F0R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F0R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F0R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F0R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F0R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F0R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F0R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F0R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F0R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F0R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F0R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F0R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F0R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F0R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F0R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F0R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F0R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F0R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F0R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F0R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define  CAN_F1R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F1R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F1R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F1R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F1R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F1R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F1R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F1R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F1R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F1R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F1R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F1R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F1R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F1R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F1R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F1R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F1R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F1R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F1R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F1R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F1R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F1R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F1R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F1R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F1R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F1R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F1R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F1R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F1R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F1R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F1R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F1R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define  CAN_F2R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F2R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F2R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F2R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F2R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F2R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F2R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F2R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F2R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F2R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F2R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F2R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F2R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F2R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F2R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F2R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F2R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F2R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F2R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F2R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F2R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F2R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F2R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F2R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F2R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F2R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F2R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F2R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F2R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F2R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F2R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F2R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define  CAN_F3R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F3R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F3R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F3R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F3R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F3R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F3R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F3R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F3R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F3R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F3R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F3R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F3R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F3R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F3R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F3R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F3R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F3R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F3R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F3R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F3R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F3R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F3R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F3R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F3R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F3R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F3R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F3R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F3R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F3R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F3R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F3R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define  CAN_F4R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F4R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F4R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F4R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F4R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F4R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F4R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F4R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F4R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F4R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F4R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F4R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F4R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F4R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F4R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F4R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F4R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F4R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F4R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F4R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F4R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F4R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F4R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F4R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F4R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F4R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F4R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F4R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F4R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F4R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F4R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F4R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define  CAN_F5R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F5R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F5R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F5R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F5R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F5R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F5R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F5R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F5R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F5R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F5R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F5R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F5R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F5R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F5R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F5R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F5R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F5R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F5R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F5R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F5R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F5R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F5R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F5R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F5R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F5R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F5R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F5R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F5R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F5R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F5R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F5R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define  CAN_F6R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F6R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F6R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F6R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F6R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F6R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F6R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F6R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F6R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F6R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F6R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F6R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F6R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F6R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F6R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F6R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F6R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F6R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F6R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F6R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F6R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F6R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F6R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F6R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F6R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F6R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F6R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F6R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F6R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F6R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F6R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F6R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define  CAN_F7R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F7R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F7R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F7R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F7R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F7R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F7R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F7R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F7R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F7R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F7R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F7R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F7R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F7R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F7R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F7R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F7R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F7R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F7R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F7R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F7R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F7R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F7R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F7R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F7R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F7R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F7R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F7R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F7R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F7R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F7R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F7R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define  CAN_F8R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F8R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F8R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F8R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F8R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F8R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F8R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F8R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F8R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F8R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F8R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F8R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F8R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F8R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F8R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F8R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F8R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F8R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F8R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F8R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F8R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F8R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F8R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F8R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F8R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F8R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F8R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F8R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F8R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F8R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F8R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F8R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define  CAN_F9R2_FB0                        ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F9R2_FB1                        ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F9R2_FB2                        ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F9R2_FB3                        ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F9R2_FB4                        ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F9R2_FB5                        ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F9R2_FB6                        ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F9R2_FB7                        ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F9R2_FB8                        ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F9R2_FB9                        ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F9R2_FB10                       ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F9R2_FB11                       ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F9R2_FB12                       ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F9R2_FB13                       ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F9R2_FB14                       ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F9R2_FB15                       ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F9R2_FB16                       ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F9R2_FB17                       ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F9R2_FB18                       ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F9R2_FB19                       ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F9R2_FB20                       ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F9R2_FB21                       ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F9R2_FB22                       ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F9R2_FB23                       ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F9R2_FB24                       ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F9R2_FB25                       ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F9R2_FB26                       ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F9R2_FB27                       ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F9R2_FB28                       ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F9R2_FB29                       ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F9R2_FB30                       ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F9R2_FB31                       ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define  CAN_F10R2_FB0                       ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F10R2_FB1                       ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F10R2_FB2                       ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F10R2_FB3                       ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F10R2_FB4                       ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F10R2_FB5                       ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F10R2_FB6                       ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F10R2_FB7                       ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F10R2_FB8                       ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F10R2_FB9                       ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F10R2_FB10                      ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F10R2_FB11                      ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F10R2_FB12                      ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F10R2_FB13                      ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F10R2_FB14                      ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F10R2_FB15                      ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F10R2_FB16                      ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F10R2_FB17                      ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F10R2_FB18                      ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F10R2_FB19                      ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F10R2_FB20                      ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F10R2_FB21                      ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F10R2_FB22                      ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F10R2_FB23                      ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F10R2_FB24                      ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F10R2_FB25                      ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F10R2_FB26                      ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F10R2_FB27                      ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F10R2_FB28                      ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F10R2_FB29                      ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F10R2_FB30                      ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F10R2_FB31                      ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define  CAN_F11R2_FB0                       ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F11R2_FB1                       ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F11R2_FB2                       ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F11R2_FB3                       ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F11R2_FB4                       ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F11R2_FB5                       ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F11R2_FB6                       ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F11R2_FB7                       ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F11R2_FB8                       ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F11R2_FB9                       ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F11R2_FB10                      ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F11R2_FB11                      ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F11R2_FB12                      ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F11R2_FB13                      ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F11R2_FB14                      ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F11R2_FB15                      ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F11R2_FB16                      ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F11R2_FB17                      ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F11R2_FB18                      ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F11R2_FB19                      ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F11R2_FB20                      ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F11R2_FB21                      ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F11R2_FB22                      ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F11R2_FB23                      ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F11R2_FB24                      ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F11R2_FB25                      ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F11R2_FB26                      ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F11R2_FB27                      ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F11R2_FB28                      ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F11R2_FB29                      ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F11R2_FB30                      ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F11R2_FB31                      ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define  CAN_F12R2_FB0                       ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F12R2_FB1                       ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F12R2_FB2                       ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F12R2_FB3                       ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F12R2_FB4                       ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F12R2_FB5                       ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F12R2_FB6                       ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F12R2_FB7                       ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F12R2_FB8                       ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F12R2_FB9                       ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F12R2_FB10                      ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F12R2_FB11                      ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F12R2_FB12                      ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F12R2_FB13                      ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F12R2_FB14                      ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F12R2_FB15                      ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F12R2_FB16                      ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F12R2_FB17                      ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F12R2_FB18                      ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F12R2_FB19                      ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F12R2_FB20                      ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F12R2_FB21                      ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F12R2_FB22                      ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F12R2_FB23                      ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F12R2_FB24                      ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F12R2_FB25                      ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F12R2_FB26                      ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F12R2_FB27                      ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F12R2_FB28                      ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F12R2_FB29                      ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F12R2_FB30                      ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F12R2_FB31                      ((uint32_t)0x80000000)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define  CAN_F13R2_FB0                       ((uint32_t)0x00000001)        /*!<Filter bit 0 */
#define  CAN_F13R2_FB1                       ((uint32_t)0x00000002)        /*!<Filter bit 1 */
#define  CAN_F13R2_FB2                       ((uint32_t)0x00000004)        /*!<Filter bit 2 */
#define  CAN_F13R2_FB3                       ((uint32_t)0x00000008)        /*!<Filter bit 3 */
#define  CAN_F13R2_FB4                       ((uint32_t)0x00000010)        /*!<Filter bit 4 */
#define  CAN_F13R2_FB5                       ((uint32_t)0x00000020)        /*!<Filter bit 5 */
#define  CAN_F13R2_FB6                       ((uint32_t)0x00000040)        /*!<Filter bit 6 */
#define  CAN_F13R2_FB7                       ((uint32_t)0x00000080)        /*!<Filter bit 7 */
#define  CAN_F13R2_FB8                       ((uint32_t)0x00000100)        /*!<Filter bit 8 */
#define  CAN_F13R2_FB9                       ((uint32_t)0x00000200)        /*!<Filter bit 9 */
#define  CAN_F13R2_FB10                      ((uint32_t)0x00000400)        /*!<Filter bit 10 */
#define  CAN_F13R2_FB11                      ((uint32_t)0x00000800)        /*!<Filter bit 11 */
#define  CAN_F13R2_FB12                      ((uint32_t)0x00001000)        /*!<Filter bit 12 */
#define  CAN_F13R2_FB13                      ((uint32_t)0x00002000)        /*!<Filter bit 13 */
#define  CAN_F13R2_FB14                      ((uint32_t)0x00004000)        /*!<Filter bit 14 */
#define  CAN_F13R2_FB15                      ((uint32_t)0x00008000)        /*!<Filter bit 15 */
#define  CAN_F13R2_FB16                      ((uint32_t)0x00010000)        /*!<Filter bit 16 */
#define  CAN_F13R2_FB17                      ((uint32_t)0x00020000)        /*!<Filter bit 17 */
#define  CAN_F13R2_FB18                      ((uint32_t)0x00040000)        /*!<Filter bit 18 */
#define  CAN_F13R2_FB19                      ((uint32_t)0x00080000)        /*!<Filter bit 19 */
#define  CAN_F13R2_FB20                      ((uint32_t)0x00100000)        /*!<Filter bit 20 */
#define  CAN_F13R2_FB21                      ((uint32_t)0x00200000)        /*!<Filter bit 21 */
#define  CAN_F13R2_FB22                      ((uint32_t)0x00400000)        /*!<Filter bit 22 */
#define  CAN_F13R2_FB23                      ((uint32_t)0x00800000)        /*!<Filter bit 23 */
#define  CAN_F13R2_FB24                      ((uint32_t)0x01000000)        /*!<Filter bit 24 */
#define  CAN_F13R2_FB25                      ((uint32_t)0x02000000)        /*!<Filter bit 25 */
#define  CAN_F13R2_FB26                      ((uint32_t)0x04000000)        /*!<Filter bit 26 */
#define  CAN_F13R2_FB27                      ((uint32_t)0x08000000)        /*!<Filter bit 27 */
#define  CAN_F13R2_FB28                      ((uint32_t)0x10000000)        /*!<Filter bit 28 */
#define  CAN_F13R2_FB29                      ((uint32_t)0x20000000)        /*!<Filter bit 29 */
#define  CAN_F13R2_FB30                      ((uint32_t)0x40000000)        /*!<Filter bit 30 */
#define  CAN_F13R2_FB31                      ((uint32_t)0x80000000)        /*!<Filter bit 31 */


/******************************************************************************/
/*                                                                            */
/*                                 HDMI-CEC (CEC)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for CEC_CR register  *********************/
#define  CEC_CR_CECEN                        ((uint32_t)0x00000001)       /*!< CEC Enable                         */
#define  CEC_CR_TXSOM                        ((uint32_t)0x00000002)       /*!< CEC Tx Start Of Message            */
#define  CEC_CR_TXEOM                        ((uint32_t)0x00000004)       /*!< CEC Tx End Of Message              */

/*******************  Bit definition for CEC_CFGR register  *******************/
#define  CEC_CFGR_SFT                        ((uint32_t)0x00000007)       /*!< CEC Signal Free Time               */
#define  CEC_CFGR_RXTOL                      ((uint32_t)0x00000008)       /*!< CEC Tolerance                      */
#define  CEC_CFGR_BRESTP                     ((uint32_t)0x00000010)       /*!< CEC Rx Stop                        */
#define  CEC_CFGR_BREGEN                     ((uint32_t)0x00000020)       /*!< CEC Bit Rising Error generation    */
#define  CEC_CFGR_LREGEN                     ((uint32_t)0x00000040)       /*!< CEC Long Period Error generation   */
#define  CEC_CFGR_BRDNOGEN                   ((uint32_t)0x00000080)       /*!< CEC Broadcast no Error generation  */
#define  CEC_CFGR_SFTOPT                     ((uint32_t)0x00000100)       /*!< CEC Signal Free Time optional      */
#define  CEC_CFGR_OAR                        ((uint32_t)0x7FFF0000)       /*!< CEC Own Address                    */
#define  CEC_CFGR_LSTN                       ((uint32_t)0x80000000)       /*!< CEC Listen mode                    */

/*******************  Bit definition for CEC_TXDR register  *******************/
#define  CEC_TXDR_TXD                        ((uint32_t)0x000000FF)       /*!< CEC Tx Data                        */

/*******************  Bit definition for CEC_RXDR register  *******************/
#define  CEC_TXDR_RXD                        ((uint32_t)0x000000FF)       /*!< CEC Rx Data                        */

/*******************  Bit definition for CEC_ISR register  ********************/
#define  CEC_ISR_RXBR                        ((uint32_t)0x00000001)       /*!< CEC Rx-Byte Received                   */
#define  CEC_ISR_RXEND                       ((uint32_t)0x00000002)       /*!< CEC End Of Reception                   */
#define  CEC_ISR_RXOVR                       ((uint32_t)0x00000004)       /*!< CEC Rx-Overrun                         */
#define  CEC_ISR_BRE                         ((uint32_t)0x00000008)       /*!< CEC Rx Bit Rising Error                */
#define  CEC_ISR_SBPE                        ((uint32_t)0x00000010)       /*!< CEC Rx Short Bit period Error          */
#define  CEC_ISR_LBPE                        ((uint32_t)0x00000020)       /*!< CEC Rx Long Bit period Error           */
#define  CEC_ISR_RXACKE                      ((uint32_t)0x00000040)       /*!< CEC Rx Missing Acknowledge             */
#define  CEC_ISR_ARBLST                      ((uint32_t)0x00000080)       /*!< CEC Arbitration Lost                   */
#define  CEC_ISR_TXBR                        ((uint32_t)0x00000100)       /*!< CEC Tx Byte Request                    */
#define  CEC_ISR_TXEND                       ((uint32_t)0x00000200)       /*!< CEC End of Transmission                */
#define  CEC_ISR_TXUDR                       ((uint32_t)0x00000400)       /*!< CEC Tx-Buffer Underrun                 */
#define  CEC_ISR_TXERR                       ((uint32_t)0x00000800)       /*!< CEC Tx-Error                           */
#define  CEC_ISR_TXACKE                      ((uint32_t)0x00001000)       /*!< CEC Tx Missing Acknowledge             */

/*******************  Bit definition for CEC_IER register  ********************/
#define  CEC_IER_RXBRIE                      ((uint32_t)0x00000001)       /*!< CEC Rx-Byte Received IT Enable         */
#define  CEC_IER_RXENDIE                     ((uint32_t)0x00000002)       /*!< CEC End Of Reception IT Enable         */
#define  CEC_IER_RXOVRIE                     ((uint32_t)0x00000004)       /*!< CEC Rx-Overrun IT Enable               */
#define  CEC_IER_BREIEIE                     ((uint32_t)0x00000008)       /*!< CEC Rx Bit Rising Error IT Enable      */
#define  CEC_IER_SBPEIE                      ((uint32_t)0x00000010)       /*!< CEC Rx Short Bit period Error IT Enable*/
#define  CEC_IER_LBPEIE                      ((uint32_t)0x00000020)       /*!< CEC Rx Long Bit period Error IT Enable */
#define  CEC_IER_RXACKEIE                    ((uint32_t)0x00000040)       /*!< CEC Rx Missing Acknowledge IT Enable   */
#define  CEC_IER_ARBLSTIE                    ((uint32_t)0x00000080)       /*!< CEC Arbitration Lost IT Enable         */
#define  CEC_IER_TXBRIE                      ((uint32_t)0x00000100)       /*!< CEC Tx Byte Request  IT Enable         */
#define  CEC_IER_TXENDIE                     ((uint32_t)0x00000200)       /*!< CEC End of Transmission IT Enable      */
#define  CEC_IER_TXUDRIE                     ((uint32_t)0x00000400)       /*!< CEC Tx-Buffer Underrun IT Enable       */
#define  CEC_IER_TXERRIE                     ((uint32_t)0x00000800)       /*!< CEC Tx-Error IT Enable                 */
#define  CEC_IER_TXACKEIE                    ((uint32_t)0x00001000)       /*!< CEC Tx Missing Acknowledge IT Enable   */

/******************************************************************************/
/*                                                                            */
/*                      Analog Comparators (COMP)                             */
/*                                                                            */
/******************************************************************************/
/***********************  Bit definition for COMP_CSR register  ***************/
/* COMP1 bits definition */
#define COMP_CSR_COMP1EN               ((uint32_t)0x00000001) /*!< COMP1 enable */
#define COMP_CSR_COMP1SW1              ((uint32_t)0x00000002) /*!< SW1 switch control */
#define COMP_CSR_COMP1MODE             ((uint32_t)0x0000000C) /*!< COMP1 power mode */
#define COMP_CSR_COMP1MODE_0           ((uint32_t)0x00000004) /*!< COMP1 power mode bit 0 */
#define COMP_CSR_COMP1MODE_1           ((uint32_t)0x00000008) /*!< COMP1 power mode bit 1 */
#define COMP_CSR_COMP1INSEL            ((uint32_t)0x00000070) /*!< COMP1 inverting input select */
#define COMP_CSR_COMP1INSEL_0          ((uint32_t)0x00000010) /*!< COMP1 inverting input select bit 0 */
#define COMP_CSR_COMP1INSEL_1          ((uint32_t)0x00000020) /*!< COMP1 inverting input select bit 1 */
#define COMP_CSR_COMP1INSEL_2          ((uint32_t)0x00000040) /*!< COMP1 inverting input select bit 2 */
#define COMP_CSR_COMP1OUTSEL           ((uint32_t)0x00000700) /*!< COMP1 output select */
#define COMP_CSR_COMP1OUTSEL_0         ((uint32_t)0x00000100) /*!< COMP1 output select bit 0 */
#define COMP_CSR_COMP1OUTSEL_1         ((uint32_t)0x00000200) /*!< COMP1 output select bit 1 */
#define COMP_CSR_COMP1OUTSEL_2         ((uint32_t)0x00000400) /*!< COMP1 output select bit 2 */
#define COMP_CSR_COMP1POL              ((uint32_t)0x00000800) /*!< COMP1 output polarity */
#define COMP_CSR_COMP1HYST             ((uint32_t)0x00003000) /*!< COMP1 hysteresis */
#define COMP_CSR_COMP1HYST_0           ((uint32_t)0x00001000) /*!< COMP1 hysteresis bit 0 */
#define COMP_CSR_COMP1HYST_1           ((uint32_t)0x00002000) /*!< COMP1 hysteresis bit 1 */
#define COMP_CSR_COMP1OUT              ((uint32_t)0x00004000) /*!< COMP1 output level */
#define COMP_CSR_COMP1LOCK             ((uint32_t)0x00008000) /*!< COMP1 lock */
/* COMP2 bits definition */
#define COMP_CSR_COMP2EN               ((uint32_t)0x00010000) /*!< COMP2 enable */
#define COMP_CSR_COMP2MODE             ((uint32_t)0x000C0000) /*!< COMP2 power mode */
#define COMP_CSR_COMP2MODE_0           ((uint32_t)0x00040000) /*!< COMP2 power mode bit 0 */
#define COMP_CSR_COMP2MODE_1           ((uint32_t)0x00080000) /*!< COMP2 power mode bit 1 */
#define COMP_CSR_COMP2INSEL            ((uint32_t)0x00700000) /*!< COMP2 inverting input select */
#define COMP_CSR_COMP2INSEL_0          ((uint32_t)0x00100000) /*!< COMP2 inverting input select bit 0 */
#define COMP_CSR_COMP2INSEL_1          ((uint32_t)0x00200000) /*!< COMP2 inverting input select bit 1 */
#define COMP_CSR_COMP2INSEL_2          ((uint32_t)0x00400000) /*!< COMP2 inverting input select bit 2 */
#define COMP_CSR_WNDWEN                ((uint32_t)0x00800000) /*!< Comparators window mode enable */
#define COMP_CSR_COMP2OUTSEL           ((uint32_t)0x07000000) /*!< COMP2 output select */
#define COMP_CSR_COMP2OUTSEL_0         ((uint32_t)0x01000000) /*!< COMP2 output select bit 0 */
#define COMP_CSR_COMP2OUTSEL_1         ((uint32_t)0x02000000) /*!< COMP2 output select bit 1 */
#define COMP_CSR_COMP2OUTSEL_2         ((uint32_t)0x04000000) /*!< COMP2 output select bit 2 */
#define COMP_CSR_COMP2POL              ((uint32_t)0x08000000) /*!< COMP2 output polarity */
#define COMP_CSR_COMP2HYST             ((uint32_t)0x30000000) /*!< COMP2 hysteresis */
#define COMP_CSR_COMP2HYST_0           ((uint32_t)0x10000000) /*!< COMP2 hysteresis bit 0 */
#define COMP_CSR_COMP2HYST_1           ((uint32_t)0x20000000) /*!< COMP2 hysteresis bit 1 */
#define COMP_CSR_COMP2OUT              ((uint32_t)0x40000000) /*!< COMP2 output level */
#define COMP_CSR_COMP2LOCK             ((uint32_t)0x80000000) /*!< COMP2 lock */

/******************************************************************************/
/*                                                                            */
/*                       CRC calculation unit (CRC)                           */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DR register  *********************/
#define  CRC_DR_DR                           ((uint32_t)0xFFFFFFFF) /*!< Data register bits */

/*******************  Bit definition for CRC_IDR register  ********************/
#define  CRC_IDR_IDR                         ((uint8_t)0xFF)        /*!< General-purpose 8-bit data register bits */

/********************  Bit definition for CRC_CR register  ********************/
#define  CRC_CR_RESET                        ((uint32_t)0x00000001) /*!< RESET the CRC computation unit bit */
#define  CRC_CR_POLSIZE                      ((uint32_t)0x00000018) /*!< Polynomial size bits (only for STM32F072 devices)*/
#define  CRC_CR_POLSIZE_0                    ((uint32_t)0x00000008) /*!< Polynomial size bit 0 (only for STM32F072 devices) */
#define  CRC_CR_POLSIZE_1                    ((uint32_t)0x00000010) /*!< Polynomial size bit 1 (only for STM32F072 devices) */
#define  CRC_CR_REV_IN                       ((uint32_t)0x00000060) /*!< REV_IN Reverse Input Data bits */
#define  CRC_CR_REV_IN_0                     ((uint32_t)0x00000020) /*!< REV_IN Bit 0 */
#define  CRC_CR_REV_IN_1                     ((uint32_t)0x00000040) /*!< REV_IN Bit 1 */
#define  CRC_CR_REV_OUT                      ((uint32_t)0x00000080) /*!< REV_OUT Reverse Output Data bits */

/*******************  Bit definition for CRC_INIT register  *******************/
#define  CRC_INIT_INIT                       ((uint32_t)0xFFFFFFFF) /*!< Initial CRC value bits */

/*******************  Bit definition for CRC_POL register  ********************/
#define  CRC_POL_POL                         ((uint32_t)0xFFFFFFFF) /*!< Coefficients of the polynomial (only for STM32F072 devices) */

/******************************************************************************/
/*                                                                            */
/*                          CRS Clock Recovery System                         */
/*                   (Available only for STM32F072 devices)                */
/******************************************************************************/

/*******************  Bit definition for CRS_CR register  *********************/
#define  CRS_CR_SYNCOKIE                     ((uint32_t)0x00000001) /* SYNC event OK interrupt enable        */
#define  CRS_CR_SYNCWARNIE                   ((uint32_t)0x00000002) /* SYNC warning interrupt enable         */
#define  CRS_CR_ERRIE                        ((uint32_t)0x00000004) /* SYNC error interrupt enable           */
#define  CRS_CR_ESYNCIE                      ((uint32_t)0x00000008) /* Expected SYNC(ESYNCF) interrupt Enable*/
#define  CRS_CR_CEN                          ((uint32_t)0x00000020) /* Frequency error counter enable        */
#define  CRS_CR_AUTOTRIMEN                   ((uint32_t)0x00000040) /* Automatic trimming enable             */
#define  CRS_CR_SWSYNC                       ((uint32_t)0x00000080) /* A Software SYNC event is generated    */
#define  CRS_CR_TRIM                         ((uint32_t)0x00003F00) /* HSI48 oscillator smooth trimming      */

/*******************  Bit definition for CRS_CFGR register  *********************/
#define  CRS_CFGR_RELOAD                     ((uint32_t)0x0000FFFF) /* Counter reload value               */
#define  CRS_CFGR_FELIM                      ((uint32_t)0x00FF0000) /* Frequency error limit              */
#define  CRS_CFGR_SYNCDIV                    ((uint32_t)0x07000000) /* SYNC divider                       */
#define  CRS_CFGR_SYNCDIV_0                  ((uint32_t)0x01000000) /* Bit 0                              */
#define  CRS_CFGR_SYNCDIV_1                  ((uint32_t)0x02000000) /* Bit 1                              */
#define  CRS_CFGR_SYNCDIV_2                  ((uint32_t)0x04000000) /* Bit 2                              */
#define  CRS_CFGR_SYNCSRC                    ((uint32_t)0x30000000) /* SYNC signal source selection       */
#define  CRS_CFGR_SYNCSRC_0                  ((uint32_t)0x10000000) /* Bit 0                              */
#define  CRS_CFGR_SYNCSRC_1                  ((uint32_t)0x20000000) /* Bit 1                              */
#define  CRS_CFGR_SYNCPOL                    ((uint32_t)0x80000000) /* SYNC polarity selection            */

/*******************  Bit definition for CRS_ISR register  *********************/
#define  CRS_ISR_SYNCOKF                     ((uint32_t)0x00000001) /* SYNC event OK flag             */
#define  CRS_ISR_SYNCWARNF                   ((uint32_t)0x00000002) /* SYNC warning                   */
#define  CRS_ISR_ERRF                        ((uint32_t)0x00000004) /* SYNC error flag                */
#define  CRS_ISR_ESYNCF                      ((uint32_t)0x00000008) /* Expected SYNC flag             */
#define  CRS_ISR_SYNCERR                     ((uint32_t)0x00000100) /* SYNC error                     */
#define  CRS_ISR_SYNCMISS                    ((uint32_t)0x00000200) /* SYNC missed                    */
#define  CRS_ISR_TRIMOVF                     ((uint32_t)0x00000400) /* Trimming overflow or underflow */
#define  CRS_ISR_FEDIR                       ((uint32_t)0x00008000) /* Frequency error direction      */
#define  CRS_ISR_FECAP                       ((uint32_t)0xFFFF0000) /* Frequency error capture        */

/*******************  Bit definition for CRS_ICR register  *********************/
#define  CRS_ICR_SYNCOKC                     ((uint32_t)0x00000001) /* SYNC event OK clear flag     */
#define  CRS_ICR_SYNCWARNC                   ((uint32_t)0x00000002) /* SYNC warning clear flag      */
#define  CRS_ICR_ERRC                        ((uint32_t)0x00000004) /* Error clear flag        */
#define  CRS_ICR_ESYNCC                      ((uint32_t)0x00000008) /* Expected SYNC clear flag     */

/******************************************************************************/
/*                                                                            */
/*                 Digital to Analog Converter (DAC)                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DAC_CR register  ********************/
#define  DAC_CR_EN1                          ((uint32_t)0x00000001)        /*!< DAC channel1 enable */
#define  DAC_CR_BOFF1                        ((uint32_t)0x00000002)        /*!< DAC channel1 output buffer disable */
#define  DAC_CR_TEN1                         ((uint32_t)0x00000004)        /*!< DAC channel1 Trigger enable */

#define  DAC_CR_TSEL1                        ((uint32_t)0x00000038)        /*!< TSEL1[2:0] (DAC channel1 Trigger selection) */
#define  DAC_CR_TSEL1_0                      ((uint32_t)0x00000008)        /*!< Bit 0 */
#define  DAC_CR_TSEL1_1                      ((uint32_t)0x00000010)        /*!< Bit 1 */
#define  DAC_CR_TSEL1_2                      ((uint32_t)0x00000020)        /*!< Bit 2 */

#define  DAC_CR_WAVE1                        ((uint32_t)0x000000C0)        /*!< WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable)(only for STM32F072 devices) */
#define  DAC_CR_WAVE1_0                      ((uint32_t)0x00000040)        /*!< Bit 0 */
#define  DAC_CR_WAVE1_1                      ((uint32_t)0x00000080)        /*!< Bit 1 */

#define  DAC_CR_MAMP1                        ((uint32_t)0x00000F00)        /*!< MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) (only for STM32F072 devices) */
#define  DAC_CR_MAMP1_0                      ((uint32_t)0x00000100)        /*!< Bit 0 */
#define  DAC_CR_MAMP1_1                      ((uint32_t)0x00000200)        /*!< Bit 1 */
#define  DAC_CR_MAMP1_2                      ((uint32_t)0x00000400)        /*!< Bit 2 */
#define  DAC_CR_MAMP1_3                      ((uint32_t)0x00000800)        /*!< Bit 3 */

#define  DAC_CR_DMAEN1                       ((uint32_t)0x00001000)        /*!< DAC channel1 DMA enable */
#define  DAC_CR_DMAUDRIE1                    ((uint32_t)0x00002000)        /*!<DAC channel1 DMA Underrun Interrupt enable */
#define  DAC_CR_EN2                          ((uint32_t)0x00010000)        /*!< DAC channel2 enable */
#define  DAC_CR_BOFF2                        ((uint32_t)0x00020000)        /*!< DAC channel2 output buffer disable */
#define  DAC_CR_TEN2                         ((uint32_t)0x00040000)        /*!< DAC channel2 Trigger enable */

#define  DAC_CR_TSEL2                        ((uint32_t)0x00380000)        /*!< TSEL2[2:0] (DAC channel2 Trigger selection) */
#define  DAC_CR_TSEL2_0                      ((uint32_t)0x00080000)        /*!< Bit 0 */
#define  DAC_CR_TSEL2_1                      ((uint32_t)0x00100000)        /*!< Bit 1 */
#define  DAC_CR_TSEL2_2                      ((uint32_t)0x00200000)        /*!< Bit 2 */

#define  DAC_CR_WAVE2                        ((uint32_t)0x00C00000)        /*!< WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define  DAC_CR_WAVE2_0                      ((uint32_t)0x00400000)        /*!< Bit 0 */
#define  DAC_CR_WAVE2_1                      ((uint32_t)0x00800000)        /*!< Bit 1 */

#define  DAC_CR_MAMP2                        ((uint32_t)0x0F000000)        /*!< MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define  DAC_CR_MAMP2_0                      ((uint32_t)0x01000000)        /*!< Bit 0 */
#define  DAC_CR_MAMP2_1                      ((uint32_t)0x02000000)        /*!< Bit 1 */
#define  DAC_CR_MAMP2_2                      ((uint32_t)0x04000000)        /*!< Bit 2 */
#define  DAC_CR_MAMP2_3                      ((uint32_t)0x08000000)        /*!< Bit 3 */

#define  DAC_CR_DMAEN2                       ((uint32_t)0x10000000)        /*!< DAC channel2 DMA enabled */
#define  DAC_CR_DMAUDRIE2                    ((uint32_t)0x20000000)        /*!<DAC channel2 DMA Underrun Interrupt enable */

/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define  DAC_SWTRIGR_SWTRIG1                 ((uint32_t)0x00000001)        /*!<DAC channel1 software trigger */
#define  DAC_SWTRIGR_SWTRIG2                 ((uint32_t)0x00000002)        /*!<DAC channel2 software trigger */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define  DAC_DHR12R1_DACC1DHR                ((uint32_t)0x00000FFF)        /*!<DAC channel1 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define  DAC_DHR12L1_DACC1DHR                ((uint32_t)0x0000FFF0)        /*!<DAC channel1 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define  DAC_DHR8R1_DACC1DHR                 ((uint32_t)0x000000FF)         /*!<DAC channel1 8-bit Right aligned data */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define  DAC_DOR1_DACC1DOR                   ((uint32_t)0x00000FFF)        /*!<DAC channel1 data output */

/********************  Bit definition for DAC_SR register  ********************/
#define  DAC_SR_DMAUDR1                      ((uint32_t)0x00002000)        /*!< DAC channel1 DMA underrun flag */
#define  DAC_SR_DMAUDR2                      ((uint32_t)0x20000000)        /*!< DAC channel2 DMA underrun flag (only for STM32F072 and STM32F042 devices) */

/******************************************************************************/
/*                                                                            */
/*                           Debug MCU (DBGMCU)                               */
/*                                                                            */
/******************************************************************************/

/****************  Bit definition for DBGMCU_IDCODE register  *****************/
#define  DBGMCU_IDCODE_DEV_ID                ((uint32_t)0x00000FFF)        /*!< Device Identifier */

#define  DBGMCU_IDCODE_REV_ID                ((uint32_t)0xFFFF0000)        /*!< REV_ID[15:0] bits (Revision Identifier) */
#define  DBGMCU_IDCODE_REV_ID_0              ((uint32_t)0x00010000)        /*!< Bit 0 */
#define  DBGMCU_IDCODE_REV_ID_1              ((uint32_t)0x00020000)        /*!< Bit 1 */
#define  DBGMCU_IDCODE_REV_ID_2              ((uint32_t)0x00040000)        /*!< Bit 2 */
#define  DBGMCU_IDCODE_REV_ID_3              ((uint32_t)0x00080000)        /*!< Bit 3 */
#define  DBGMCU_IDCODE_REV_ID_4              ((uint32_t)0x00100000)        /*!< Bit 4 */
#define  DBGMCU_IDCODE_REV_ID_5              ((uint32_t)0x00200000)        /*!< Bit 5 */
#define  DBGMCU_IDCODE_REV_ID_6              ((uint32_t)0x00400000)        /*!< Bit 6 */
#define  DBGMCU_IDCODE_REV_ID_7              ((uint32_t)0x00800000)        /*!< Bit 7 */
#define  DBGMCU_IDCODE_REV_ID_8              ((uint32_t)0x01000000)        /*!< Bit 8 */
#define  DBGMCU_IDCODE_REV_ID_9              ((uint32_t)0x02000000)        /*!< Bit 9 */
#define  DBGMCU_IDCODE_REV_ID_10             ((uint32_t)0x04000000)        /*!< Bit 10 */
#define  DBGMCU_IDCODE_REV_ID_11             ((uint32_t)0x08000000)        /*!< Bit 11 */
#define  DBGMCU_IDCODE_REV_ID_12             ((uint32_t)0x10000000)        /*!< Bit 12 */
#define  DBGMCU_IDCODE_REV_ID_13             ((uint32_t)0x20000000)        /*!< Bit 13 */
#define  DBGMCU_IDCODE_REV_ID_14             ((uint32_t)0x40000000)        /*!< Bit 14 */
#define  DBGMCU_IDCODE_REV_ID_15             ((uint32_t)0x80000000)        /*!< Bit 15 */

/******************  Bit definition for DBGMCU_CR register  *******************/
#define  DBGMCU_CR_DBG_STOP                  ((uint32_t)0x00000002)        /*!< Debug Stop Mode */
#define  DBGMCU_CR_DBG_STANDBY               ((uint32_t)0x00000004)        /*!< Debug Standby mode */

/******************  Bit definition for DBGMCU_APB1_FZ register  **************/
#define  DBGMCU_APB1_FZ_DBG_TIM2_STOP        ((uint32_t)0x00000001)        /*!< TIM2 counter stopped when core is halted */
#define  DBGMCU_APB1_FZ_DBG_TIM3_STOP        ((uint32_t)0x00000002)        /*!< TIM3 counter stopped when core is halted */
#define  DBGMCU_APB1_FZ_DBG_TIM6_STOP        ((uint32_t)0x00000010)        /*!< TIM6 counter stopped when core is halted (not available on STM32F042 devices)*/
#define  DBGMCU_APB1_FZ_DBG_TIM7_STOP        ((uint32_t)0x00000020)        /*!< TIM7 counter stopped when core is halted (only for STM32F072 devices) */
#define  DBGMCU_APB1_FZ_DBG_TIM14_STOP       ((uint32_t)0x00000100)        /*!< TIM14 counter stopped when core is halted */
#define  DBGMCU_APB1_FZ_DBG_RTC_STOP         ((uint32_t)0x00000400)        /*!< RTC Calendar frozen when core is halted */
#define  DBGMCU_APB1_FZ_DBG_WWDG_STOP        ((uint32_t)0x00000800)        /*!< Debug Window Watchdog stopped when Core is halted */
#define  DBGMCU_APB1_FZ_DBG_IWDG_STOP        ((uint32_t)0x00001000)        /*!< Debug Independent Watchdog stopped when Core is halted */
#define  DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT    ((uint32_t)0x00200000)   /*!< I2C1 SMBUS timeout mode stopped when Core is halted */
#define  DBGMCU_APB1_FZ_DBG_CAN_STOP         ((uint32_t)0x02000000)        /*!< CAN debug stopped when Core is halted (only for STM32F072 devices) */

/******************  Bit definition for DBGMCU_APB2_FZ register  **************/
#define  DBGMCU_APB2_FZ_DBG_TIM1_STOP        ((uint32_t)0x00000800)        /*!< TIM1 counter stopped when core is halted */
#define  DBGMCU_APB2_FZ_DBG_TIM15_STOP       ((uint32_t)0x00010000)        /*!< TIM15 counter stopped when core is halted (not available on STM32F042 devices) */
#define  DBGMCU_APB2_FZ_DBG_TIM16_STOP       ((uint32_t)0x00020000)        /*!< TIM16 counter stopped when core is halted */
#define  DBGMCU_APB2_FZ_DBG_TIM17_STOP       ((uint32_t)0x00040000)        /*!< TIM17 counter stopped when core is halted */

/******************************************************************************/
/*                                                                            */
/*                           DMA Controller (DMA)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for DMA_ISR register  ********************/
#define  DMA_ISR_GIF1                        ((uint32_t)0x00000001)        /*!< Channel 1 Global interrupt flag    */
#define  DMA_ISR_TCIF1                       ((uint32_t)0x00000002)        /*!< Channel 1 Transfer Complete flag   */
#define  DMA_ISR_HTIF1                       ((uint32_t)0x00000004)        /*!< Channel 1 Half Transfer flag       */
#define  DMA_ISR_TEIF1                       ((uint32_t)0x00000008)        /*!< Channel 1 Transfer Error flag      */
#define  DMA_ISR_GIF2                        ((uint32_t)0x00000010)        /*!< Channel 2 Global interrupt flag    */
#define  DMA_ISR_TCIF2                       ((uint32_t)0x00000020)        /*!< Channel 2 Transfer Complete flag   */
#define  DMA_ISR_HTIF2                       ((uint32_t)0x00000040)        /*!< Channel 2 Half Transfer flag       */
#define  DMA_ISR_TEIF2                       ((uint32_t)0x00000080)        /*!< Channel 2 Transfer Error flag      */
#define  DMA_ISR_GIF3                        ((uint32_t)0x00000100)        /*!< Channel 3 Global interrupt flag    */
#define  DMA_ISR_TCIF3                       ((uint32_t)0x00000200)        /*!< Channel 3 Transfer Complete flag   */
#define  DMA_ISR_HTIF3                       ((uint32_t)0x00000400)        /*!< Channel 3 Half Transfer flag       */
#define  DMA_ISR_TEIF3                       ((uint32_t)0x00000800)        /*!< Channel 3 Transfer Error flag      */
#define  DMA_ISR_GIF4                        ((uint32_t)0x00001000)        /*!< Channel 4 Global interrupt flag    */
#define  DMA_ISR_TCIF4                       ((uint32_t)0x00002000)        /*!< Channel 4 Transfer Complete flag   */
#define  DMA_ISR_HTIF4                       ((uint32_t)0x00004000)        /*!< Channel 4 Half Transfer flag       */
#define  DMA_ISR_TEIF4                       ((uint32_t)0x00008000)        /*!< Channel 4 Transfer Error flag      */
#define  DMA_ISR_GIF5                        ((uint32_t)0x00010000)        /*!< Channel 5 Global interrupt flag    */
#define  DMA_ISR_TCIF5                       ((uint32_t)0x00020000)        /*!< Channel 5 Transfer Complete flag   */
#define  DMA_ISR_HTIF5                       ((uint32_t)0x00040000)        /*!< Channel 5 Half Transfer flag       */
#define  DMA_ISR_TEIF5                       ((uint32_t)0x00080000)        /*!< Channel 5 Transfer Error flag      */
#define  DMA_ISR_GIF6                        ((uint32_t)0x00100000)        /*!< Channel 6 Global interrupt flag (only for STM32F072 devices) */
#define  DMA_ISR_TCIF6                       ((uint32_t)0x00200000)        /*!< Channel 6 Transfer Complete flag (only for STM32F072 devices) */
#define  DMA_ISR_HTIF6                       ((uint32_t)0x00400000)        /*!< Channel 6 Half Transfer flag (only for STM32F072 devices) */
#define  DMA_ISR_TEIF6                       ((uint32_t)0x00800000)        /*!< Channel 6 Transfer Error flag (only for STM32F072 devices) */
#define  DMA_ISR_GIF7                        ((uint32_t)0x01000000)        /*!< Channel 7 Global interrupt flag (only for STM32F072 devices) */
#define  DMA_ISR_TCIF7                       ((uint32_t)0x02000000)        /*!< Channel 7 Transfer Complete flag (only for STM32F072 devices) */
#define  DMA_ISR_HTIF7                       ((uint32_t)0x04000000)        /*!< Channel 7 Half Transfer flag (only for STM32F072 devices) */
#define  DMA_ISR_TEIF7                       ((uint32_t)0x08000000)        /*!< Channel 7 Transfer Error flag (only for STM32F072 devices) */

/*******************  Bit definition for DMA_IFCR register  *******************/
#define  DMA_IFCR_CGIF1                      ((uint32_t)0x00000001)        /*!< Channel 1 Global interrupt clear    */
#define  DMA_IFCR_CTCIF1                     ((uint32_t)0x00000002)        /*!< Channel 1 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF1                     ((uint32_t)0x00000004)        /*!< Channel 1 Half Transfer clear       */
#define  DMA_IFCR_CTEIF1                     ((uint32_t)0x00000008)        /*!< Channel 1 Transfer Error clear      */
#define  DMA_IFCR_CGIF2                      ((uint32_t)0x00000010)        /*!< Channel 2 Global interrupt clear    */
#define  DMA_IFCR_CTCIF2                     ((uint32_t)0x00000020)        /*!< Channel 2 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF2                     ((uint32_t)0x00000040)        /*!< Channel 2 Half Transfer clear       */
#define  DMA_IFCR_CTEIF2                     ((uint32_t)0x00000080)        /*!< Channel 2 Transfer Error clear      */
#define  DMA_IFCR_CGIF3                      ((uint32_t)0x00000100)        /*!< Channel 3 Global interrupt clear    */
#define  DMA_IFCR_CTCIF3                     ((uint32_t)0x00000200)        /*!< Channel 3 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF3                     ((uint32_t)0x00000400)        /*!< Channel 3 Half Transfer clear       */
#define  DMA_IFCR_CTEIF3                     ((uint32_t)0x00000800)        /*!< Channel 3 Transfer Error clear      */
#define  DMA_IFCR_CGIF4                      ((uint32_t)0x00001000)        /*!< Channel 4 Global interrupt clear    */
#define  DMA_IFCR_CTCIF4                     ((uint32_t)0x00002000)        /*!< Channel 4 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF4                     ((uint32_t)0x00004000)        /*!< Channel 4 Half Transfer clear       */
#define  DMA_IFCR_CTEIF4                     ((uint32_t)0x00008000)        /*!< Channel 4 Transfer Error clear      */
#define  DMA_IFCR_CGIF5                      ((uint32_t)0x00010000)        /*!< Channel 5 Global interrupt clear    */
#define  DMA_IFCR_CTCIF5                     ((uint32_t)0x00020000)        /*!< Channel 5 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF5                     ((uint32_t)0x00040000)        /*!< Channel 5 Half Transfer clear       */
#define  DMA_IFCR_CTEIF5                     ((uint32_t)0x00080000)        /*!< Channel 5 Transfer Error clear      */
#define  DMA_IFCR_CGIF6                      ((uint32_t)0x00100000)        /*!< Channel 6 Global interrupt clear (only for STM32F072 devices) */
#define  DMA_IFCR_CTCIF6                     ((uint32_t)0x00200000)        /*!< Channel 6 Transfer Complete clear (only for STM32F072 devices) */
#define  DMA_IFCR_CHTIF6                     ((uint32_t)0x00400000)        /*!< Channel 6 Half Transfer clear (only for STM32F072 devices) */
#define  DMA_IFCR_CTEIF6                     ((uint32_t)0x00800000)        /*!< Channel 6 Transfer Error clear (only for STM32F072 devices) */
#define  DMA_IFCR_CGIF7                      ((uint32_t)0x01000000)        /*!< Channel 7 Global interrupt clear (only for STM32F072 devices) */
#define  DMA_IFCR_CTCIF7                     ((uint32_t)0x02000000)        /*!< Channel 7 Transfer Complete clear (only for STM32F072 devices) */
#define  DMA_IFCR_CHTIF7                     ((uint32_t)0x04000000)        /*!< Channel 7 Half Transfer clear (only for STM32F072 devices) */
#define  DMA_IFCR_CTEIF7                     ((uint32_t)0x08000000)        /*!< Channel 7 Transfer Error clear (only for STM32F072 devices) */

/*******************  Bit definition for DMA_CCR register  ********************/
#define  DMA_CCR_EN                          ((uint32_t)0x00000001)        /*!< Channel enable                      */
#define  DMA_CCR_TCIE                        ((uint32_t)0x00000002)        /*!< Transfer complete interrupt enable  */
#define  DMA_CCR_HTIE                        ((uint32_t)0x00000004)        /*!< Half Transfer interrupt enable      */
#define  DMA_CCR_TEIE                        ((uint32_t)0x00000008)        /*!< Transfer error interrupt enable     */
#define  DMA_CCR_DIR                         ((uint32_t)0x00000010)        /*!< Data transfer direction             */
#define  DMA_CCR_CIRC                        ((uint32_t)0x00000020)        /*!< Circular mode                       */
#define  DMA_CCR_PINC                        ((uint32_t)0x00000040)        /*!< Peripheral increment mode           */
#define  DMA_CCR_MINC                        ((uint32_t)0x00000080)        /*!< Memory increment mode               */

#define  DMA_CCR_PSIZE                       ((uint32_t)0x00000300)        /*!< PSIZE[1:0] bits (Peripheral size)   */
#define  DMA_CCR_PSIZE_0                     ((uint32_t)0x00000100)        /*!< Bit 0                               */
#define  DMA_CCR_PSIZE_1                     ((uint32_t)0x00000200)        /*!< Bit 1                               */

#define  DMA_CCR_MSIZE                       ((uint32_t)0x00000C00)        /*!< MSIZE[1:0] bits (Memory size)       */
#define  DMA_CCR_MSIZE_0                     ((uint32_t)0x00000400)        /*!< Bit 0                               */
#define  DMA_CCR_MSIZE_1                     ((uint32_t)0x00000800)        /*!< Bit 1                               */

#define  DMA_CCR_PL                          ((uint32_t)0x00003000)        /*!< PL[1:0] bits(Channel Priority level)*/
#define  DMA_CCR_PL_0                        ((uint32_t)0x00001000)        /*!< Bit 0                               */
#define  DMA_CCR_PL_1                        ((uint32_t)0x00002000)        /*!< Bit 1                               */

#define  DMA_CCR_MEM2MEM                     ((uint32_t)0x00004000)        /*!< Memory to memory mode               */

/******************  Bit definition for DMA_CNDTR register  *******************/
#define  DMA_CNDTR_NDT                       ((uint32_t)0x0000FFFF)        /*!< Number of data to Transfer          */

/******************  Bit definition for DMA_CPAR register  ********************/
#define  DMA_CPAR_PA                         ((uint32_t)0xFFFFFFFF)        /*!< Peripheral Address                  */

/******************  Bit definition for DMA_CMAR register  ********************/
#define  DMA_CMAR_MA                         ((uint32_t)0xFFFFFFFF)        /*!< Memory Address                      */

/******************  Bit definition for DMA_RMPCR1 register  ********************/
#define DMA_RMPCR1_DEFAULT                  ((uint32_t)0x00000000)        /*!< Default remap position for DMA1 */
#define DMA_RMPCR1_CH1_ADC                  ((uint32_t)0x00000001)        /*!< Remap ADC on DMA1 Channel 1*/
#define DMA_RMPCR1_CH1_TIM17_CH1            ((uint32_t)0x00000007)        /*!< Remap TIM17 channel 1 on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_TIM17_UP             ((uint32_t)0x00000007)        /*!< Remap TIM17 up on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_USART1_RX            ((uint32_t)0x00000008)        /*!< Remap USART1 Rx on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_USART2_RX            ((uint32_t)0x00000009)        /*!< Remap USART2 Rx on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_USART3_RX            ((uint32_t)0x0000000A)        /*!< Remap USART3 Rx on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_USART4_RX            ((uint32_t)0x0000000B)        /*!< Remap USART4 Rx on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_USART5_RX            ((uint32_t)0x0000000C)        /*!< Remap USART5 Rx on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_USART6_RX            ((uint32_t)0x0000000D)        /*!< Remap USART6 Rx on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_USART7_RX            ((uint32_t)0x0000000E)        /*!< Remap USART7 Rx on DMA1 channel 1 */
#define DMA_RMPCR1_CH1_USART8_RX            ((uint32_t)0x0000000F)        /*!< Remap USART8 Rx on DMA1 channel 1 */
#define DMA_RMPCR1_CH2_ADC                  ((uint32_t)0x00000010)        /*!< Remap ADC on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_I2C1_TX              ((uint32_t)0x00000020)        /*!< Remap I2C1 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_SPI_1RX              ((uint32_t)0x00000030)        /*!< Remap SPI1 Rx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_TIM1_CH1             ((uint32_t)0x00000040)        /*!< Remap TIM1 channel 1 on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_TIM17_CH1            ((uint32_t)0x00000070)        /*!< Remap TIM17 channel 1 on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_TIM17_UP             ((uint32_t)0x00000070)        /*!< Remap TIM17 up on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_USART1_TX            ((uint32_t)0x00000080)        /*!< Remap USART1 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_USART2_TX            ((uint32_t)0x00000090)        /*!< Remap USART2 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_USART3_TX            ((uint32_t)0x000000A0)        /*!< Remap USART3 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_USART4_TX            ((uint32_t)0x000000B0)        /*!< Remap USART4 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_USART5_TX            ((uint32_t)0x000000C0)        /*!< Remap USART5 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_USART6_TX            ((uint32_t)0x000000D0)        /*!< Remap USART6 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_USART7_TX            ((uint32_t)0x000000E0)        /*!< Remap USART7 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH2_USART8_TX            ((uint32_t)0x000000F0)        /*!< Remap USART8 Tx on DMA1 channel 2 */
#define DMA_RMPCR1_CH3_TIM6_UP              ((uint32_t)0x00000100)        /*!< Remap TIM6 up on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_DAC_CH1              ((uint32_t)0x00000100)        /*!< Remap DAC Channel 1on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_I2C1_RX              ((uint32_t)0x00000200)        /*!< Remap I2C1 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_SPI1_TX              ((uint32_t)0x00000300)        /*!< Remap SPI1 Tx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_TIM1_CH2             ((uint32_t)0x00000400)        /*!< Remap TIM1 channel 2 on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_TIM2_CH2             ((uint32_t)0x00000500)        /*!< Remap TIM2 channel 2 on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_TIM16_CH1            ((uint32_t)0x00000700)        /*!< Remap TIM16 channel 1 on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_TIM16_UP             ((uint32_t)0x00000700)        /*!< Remap TIM16 up on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_USART1_RX            ((uint32_t)0x00000800)        /*!< Remap USART1 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_USART2_RX            ((uint32_t)0x00000900)        /*!< Remap USART2 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_USART3_RX            ((uint32_t)0x00000A00)        /*!< Remap USART3 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_USART4_RX            ((uint32_t)0x00000B00)        /*!< Remap USART4 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_USART5_RX            ((uint32_t)0x00000C00)        /*!< Remap USART5 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_USART6_RX            ((uint32_t)0x00000D00)        /*!< Remap USART6 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_USART7_RX            ((uint32_t)0x00000E00)        /*!< Remap USART7 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH3_USART8_RX            ((uint32_t)0x00000F00)        /*!< Remap USART8 Rx on DMA1 channel 3 */
#define DMA_RMPCR1_CH4_TIM7_UP              ((uint32_t)0x00001000)        /*!< Remap TIM7 up on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_DAC_CH2              ((uint32_t)0x00001000)        /*!< Remap DAC Channel 2 on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_I2C2_TX              ((uint32_t)0x00002000)        /*!< Remap I2C2 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_SPI2_RX              ((uint32_t)0x00003000)        /*!< Remap SPI2 Rx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_TIM2_CH4             ((uint32_t)0x00005000)        /*!< Remap TIM2 channel 4 on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_TIM3_CH1             ((uint32_t)0x00006000)        /*!< Remap TIM3 channel 1 on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_TIM3_TRIG            ((uint32_t)0x00006000)        /*!< Remap TIM3 Trig on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_TIM16_CH1            ((uint32_t)0x00007000)        /*!< Remap TIM16 channel 1 on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_TIM16_UP             ((uint32_t)0x00007000)        /*!< Remap TIM16 up on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_USART1_TX            ((uint32_t)0x00008000)        /*!< Remap USART1 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_USART2_TX            ((uint32_t)0x00009000)        /*!< Remap USART2 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_USART3_TX            ((uint32_t)0x0000A000)        /*!< Remap USART3 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_USART4_TX            ((uint32_t)0x0000B000)        /*!< Remap USART4 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_USART5_TX            ((uint32_t)0x0000C000)        /*!< Remap USART5 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_USART6_TX            ((uint32_t)0x0000D000)        /*!< Remap USART6 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_USART7_TX            ((uint32_t)0x0000E000)        /*!< Remap USART7 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH4_USART8_TX            ((uint32_t)0x0000F000)        /*!< Remap USART8 Tx on DMA1 channel 4 */
#define DMA_RMPCR1_CH5_I2C2_RX              ((uint32_t)0x00020000)        /*!< Remap I2C2 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_SPI2_TX              ((uint32_t)0x00030000)        /*!< Remap SPI1 Tx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_TIM1_CH3             ((uint32_t)0x00040000)        /*!< Remap TIM1 channel 3 on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_USART1_RX            ((uint32_t)0x00080000)        /*!< Remap USART1 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_USART2_RX            ((uint32_t)0x00090000)        /*!< Remap USART2 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_USART3_RX            ((uint32_t)0x000A0000)        /*!< Remap USART3 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_USART4_RX            ((uint32_t)0x000B0000)        /*!< Remap USART4 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_USART5_RX            ((uint32_t)0x000C0000)        /*!< Remap USART5 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_USART6_RX            ((uint32_t)0x000D0000)        /*!< Remap USART6 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_USART7_RX            ((uint32_t)0x000E0000)        /*!< Remap USART7 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH5_USART8_RX            ((uint32_t)0x000F0000)        /*!< Remap USART8 Rx on DMA1 channel 5 */
#define DMA_RMPCR1_CH6_I2C1_TX              ((uint32_t)0x00200000)        /*!< Remap I2C1 Tx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_SPI2_RX              ((uint32_t)0x00300000)        /*!< Remap SPI2 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_TIM1_CH1             ((uint32_t)0x00400000)        /*!< Remap TIM1 channel 1 on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_TIM1_CH2             ((uint32_t)0x00400000)        /*!< Remap TIM1 channel 2 on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_TIM1_CH3             ((uint32_t)0x00400000)        /*!< Remap TIM1 channel 3 on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_TIM3_CH1             ((uint32_t)0x00600000)        /*!< Remap TIM3 channel 1 on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_TIM3_TRIG            ((uint32_t)0x00600000)        /*!< Remap TIM3 Trig on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_TIM16_CH1            ((uint32_t)0x00700000)        /*!< Remap TIM16 channel 1 on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_TIM16_UP             ((uint32_t)0x00700000)        /*!< Remap TIM16 up on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_USART1_RX            ((uint32_t)0x00800000)        /*!< Remap USART1 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_USART2_RX            ((uint32_t)0x00900000)        /*!< Remap USART2 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_USART3_RX            ((uint32_t)0x00A00000)        /*!< Remap USART3 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_USART4_RX            ((uint32_t)0x00B00000)        /*!< Remap USART4 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_USART5_RX            ((uint32_t)0x00C00000)        /*!< Remap USART5 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_USART6_RX            ((uint32_t)0x00D00000)        /*!< Remap USART6 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_USART7_RX            ((uint32_t)0x00E00000)        /*!< Remap USART7 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH6_USART8_RX            ((uint32_t)0x00F00000)        /*!< Remap USART8 Rx on DMA1 channel 6 */
#define DMA_RMPCR1_CH7_I2C1_RX              ((uint32_t)0x02000000)        /*!< Remap I2C1 Rx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_SPI2_TX              ((uint32_t)0x03000000)        /*!< Remap SPI2 Tx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_TIM2_CH2             ((uint32_t)0x05000000)        /*!< Remap TIM2 channel 2 on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_TIM2_CH4             ((uint32_t)0x05000000)        /*!< Remap TIM2 channel 4 on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_TIM17_CH1            ((uint32_t)0x07000000)        /*!< Remap TIM17 channel 1 on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_TIM17_UP             ((uint32_t)0x07000000)        /*!< Remap TIM17 up on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_USART1_TX            ((uint32_t)0x08000000)        /*!< Remap USART1 Tx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_USART2_TX            ((uint32_t)0x09000000)        /*!< Remap USART2 Tx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_USART3_TX            ((uint32_t)0x0A000000)        /*!< Remap USART3 Tx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_USART4_TX            ((uint32_t)0x0B000000)        /*!< Remap USART4 Tx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_USART5_TX            ((uint32_t)0x0C000000)        /*!< Remap USART5 Tx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_USART6_TX            ((uint32_t)0x0D000000)        /*!< Remap USART6 Tx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_USART7_TX            ((uint32_t)0x0E000000)        /*!< Remap USART7 Tx on DMA1 channel 7 */
#define DMA_RMPCR1_CH7_USART8_TX            ((uint32_t)0x0F000000)        /*!< Remap USART8 Tx on DMA1 channel 7 */

/******************  Bit definition for DMA_RMPCR2 register  ********************/
#define DMA_RMPCR2_DEFAULT                  ((uint32_t)0x00000000)        /*!< Default remap position for DMA2 */
#define DMA_RMPCR2_CH1_I2C2_TX              ((uint32_t)0x00000002)        /*!< Remap I2C2 TX on DMA2 channel 1 */
#define DMA_RMPCR2_CH1_USART1_TX            ((uint32_t)0x00000008)        /*!< Remap USART1 Tx on DMA2 channel 1 */
#define DMA_RMPCR2_CH1_USART2_TX            ((uint32_t)0x00000009)        /*!< Remap USART2 Tx on DMA2 channel 1 */
#define DMA_RMPCR2_CH1_USART3_TX            ((uint32_t)0x0000000A)        /*!< Remap USART3 Tx on DMA2 channel 1 */
#define DMA_RMPCR2_CH1_USART4_TX            ((uint32_t)0x0000000B)        /*!< Remap USART4 Tx on DMA2 channel 1 */
#define DMA_RMPCR2_CH1_USART5_TX            ((uint32_t)0x0000000C)        /*!< Remap USART5 Tx on DMA2 channel 1 */
#define DMA_RMPCR2_CH1_USART6_TX            ((uint32_t)0x0000000D)        /*!< Remap USART6 Tx on DMA2 channel 1 */
#define DMA_RMPCR2_CH1_USART7_TX            ((uint32_t)0x0000000E)        /*!< Remap USART7 Tx on DMA2 channel 1 */
#define DMA_RMPCR2_CH1_USART8_TX            ((uint32_t)0x0000000F)        /*!< Remap USART8 Tx on DMA2 channel 1 */
#define DMA_RMPCR2_CH2_I2C2_RX              ((uint32_t)0x00000020)        /*!< Remap I2C2 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH2_USART1_RX            ((uint32_t)0x00000080)        /*!< Remap USART1 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH2_USART2_RX            ((uint32_t)0x00000090)        /*!< Remap USART2 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH2_USART3_RX            ((uint32_t)0x000000A0)        /*!< Remap USART3 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH2_USART4_RX            ((uint32_t)0x000000B0)        /*!< Remap USART4 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH2_USART5_RX            ((uint32_t)0x000000C0)        /*!< Remap USART5 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH2_USART6_RX            ((uint32_t)0x000000D0)        /*!< Remap USART6 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH2_USART7_RX            ((uint32_t)0x000000E0)        /*!< Remap USART7 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH2_USART8_RX            ((uint32_t)0x000000F0)        /*!< Remap USART8 Rx on DMA2 channel 2 */
#define DMA_RMPCR2_CH3_TIM6_UP              ((uint32_t)0x00000100)        /*!< Remap TIM6 up on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_DAC_CH1              ((uint32_t)0x00000100)        /*!< Remap DAC channel 1 on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_SPI1_RX              ((uint32_t)0x00000300)        /*!< Remap SPI1 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_USART1_RX            ((uint32_t)0x00000800)        /*!< Remap USART1 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_USART2_RX            ((uint32_t)0x00000900)        /*!< Remap USART2 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_USART3_RX            ((uint32_t)0x00000A00)        /*!< Remap USART3 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_USART4_RX            ((uint32_t)0x00000B00)        /*!< Remap USART4 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_USART5_RX            ((uint32_t)0x00000C00)        /*!< Remap USART5 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_USART6_RX            ((uint32_t)0x00000D00)        /*!< Remap USART6 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_USART7_RX            ((uint32_t)0x00000E00)        /*!< Remap USART7 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH3_USART8_RX            ((uint32_t)0x00000F00)        /*!< Remap USART8 Rx on DMA2 channel 3 */
#define DMA_RMPCR2_CH4_TIM7_UP              ((uint32_t)0x00001000)        /*!< Remap TIM7 up on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_DAC_CH2              ((uint32_t)0x00001000)        /*!< Remap DAC channel 2 on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_SPI1_TX              ((uint32_t)0x00003000)        /*!< Remap SPI1 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_USART1_TX            ((uint32_t)0x00008000)        /*!< Remap USART1 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_USART2_TX            ((uint32_t)0x00009000)        /*!< Remap USART2 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_USART3_TX            ((uint32_t)0x0000A000)        /*!< Remap USART3 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_USART4_TX            ((uint32_t)0x0000B000)        /*!< Remap USART4 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_USART5_TX            ((uint32_t)0x0000C000)        /*!< Remap USART5 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_USART6_TX            ((uint32_t)0x0000D000)        /*!< Remap USART6 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_USART7_TX            ((uint32_t)0x0000E000)        /*!< Remap USART7 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH4_USART8_TX            ((uint32_t)0x0000F000)        /*!< Remap USART8 Tx on DMA2 channel 4 */
#define DMA_RMPCR2_CH5_ADC                  ((uint32_t)0x00010000)        /*!< Remap ADC on DMA2 channel 5 */
#define DMA_RMPCR2_CH5_USART1_TX            ((uint32_t)0x00080000)        /*!< Remap USART1 Tx on DMA2 channel 5 */
#define DMA_RMPCR2_CH5_USART2_TX            ((uint32_t)0x00090000)        /*!< Remap USART2 Tx on DMA2 channel 5 */
#define DMA_RMPCR2_CH5_USART3_TX            ((uint32_t)0x000A0000)        /*!< Remap USART3 Tx on DMA2 channel 5 */
#define DMA_RMPCR2_CH5_USART4_TX            ((uint32_t)0x000B0000)        /*!< Remap USART4 Tx on DMA2 channel 5 */
#define DMA_RMPCR2_CH5_USART5_TX            ((uint32_t)0x000C0000)        /*!< Remap USART5 Tx on DMA2 channel 5 */
#define DMA_RMPCR2_CH5_USART6_TX            ((uint32_t)0x000D0000)        /*!< Remap USART6 Tx on DMA2 channel 5 */
#define DMA_RMPCR2_CH5_USART7_TX            ((uint32_t)0x000E0000)        /*!< Remap USART7 Tx on DMA2 channel 5 */
#define DMA_RMPCR2_CH5_USART8_TX            ((uint32_t)0x000F0000)        /*!< Remap USART8 Tx on DMA2 channel 5 */

/******************************************************************************/
/*                                                                            */
/*                 External Interrupt/Event Controller (EXTI)                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for EXTI_IMR register  *******************/
#define  EXTI_IMR_MR0                        ((uint32_t)0x00000001)        /*!< Interrupt Mask on line 0  */
#define  EXTI_IMR_MR1                        ((uint32_t)0x00000002)        /*!< Interrupt Mask on line 1  */
#define  EXTI_IMR_MR2                        ((uint32_t)0x00000004)        /*!< Interrupt Mask on line 2  */
#define  EXTI_IMR_MR3                        ((uint32_t)0x00000008)        /*!< Interrupt Mask on line 3  */
#define  EXTI_IMR_MR4                        ((uint32_t)0x00000010)        /*!< Interrupt Mask on line 4  */
#define  EXTI_IMR_MR5                        ((uint32_t)0x00000020)        /*!< Interrupt Mask on line 5  */
#define  EXTI_IMR_MR6                        ((uint32_t)0x00000040)        /*!< Interrupt Mask on line 6  */
#define  EXTI_IMR_MR7                        ((uint32_t)0x00000080)        /*!< Interrupt Mask on line 7  */
#define  EXTI_IMR_MR8                        ((uint32_t)0x00000100)        /*!< Interrupt Mask on line 8  */
#define  EXTI_IMR_MR9                        ((uint32_t)0x00000200)        /*!< Interrupt Mask on line 9  */
#define  EXTI_IMR_MR10                       ((uint32_t)0x00000400)        /*!< Interrupt Mask on line 10 */
#define  EXTI_IMR_MR11                       ((uint32_t)0x00000800)        /*!< Interrupt Mask on line 11 */
#define  EXTI_IMR_MR12                       ((uint32_t)0x00001000)        /*!< Interrupt Mask on line 12 */
#define  EXTI_IMR_MR13                       ((uint32_t)0x00002000)        /*!< Interrupt Mask on line 13 */
#define  EXTI_IMR_MR14                       ((uint32_t)0x00004000)        /*!< Interrupt Mask on line 14 */
#define  EXTI_IMR_MR15                       ((uint32_t)0x00008000)        /*!< Interrupt Mask on line 15 */
#define  EXTI_IMR_MR16                       ((uint32_t)0x00010000)        /*!< Interrupt Mask on line 16 */
#define  EXTI_IMR_MR17                       ((uint32_t)0x00020000)        /*!< Interrupt Mask on line 17 */
#define  EXTI_IMR_MR18                       ((uint32_t)0x00040000)        /*!< Interrupt Mask on line 18 */
#define  EXTI_IMR_MR19                       ((uint32_t)0x00080000)        /*!< Interrupt Mask on line 19 */
#define  EXTI_IMR_MR20                       ((uint32_t)0x00100000)        /*!< Interrupt Mask on line 20 */
#define  EXTI_IMR_MR21                       ((uint32_t)0x00200000)        /*!< Interrupt Mask on line 21 */
#define  EXTI_IMR_MR22                       ((uint32_t)0x00400000)        /*!< Interrupt Mask on line 22 */
#define  EXTI_IMR_MR23                       ((uint32_t)0x00800000)        /*!< Interrupt Mask on line 23 */
#define  EXTI_IMR_MR24                       ((uint32_t)0x01000000)        /*!< Interrupt Mask on line 24 */
#define  EXTI_IMR_MR25                       ((uint32_t)0x02000000)        /*!< Interrupt Mask on line 25 */
#define  EXTI_IMR_MR26                       ((uint32_t)0x04000000)        /*!< Interrupt Mask on line 26 */
#define  EXTI_IMR_MR27                       ((uint32_t)0x08000000)        /*!< Interrupt Mask on line 27 */
#define  EXTI_IMR_MR28                       ((uint32_t)0x10000000)        /*!< Interrupt Mask on line 28 */
#define  EXTI_IMR_MR29                       ((uint32_t)0x20000000)        /*!< Interrupt Mask on line 29 */
#define  EXTI_IMR_MR30                       ((uint32_t)0x40000000)        /*!< Interrupt Mask on line 30 */
#define  EXTI_IMR_MR31                       ((uint32_t)0x80000000)        /*!< Interrupt Mask on line 31 */

/******************  Bit definition for EXTI_EMR register  ********************/
#define  EXTI_EMR_MR0                        ((uint32_t)0x00000001)        /*!< Event Mask on line 0  */
#define  EXTI_EMR_MR1                        ((uint32_t)0x00000002)        /*!< Event Mask on line 1  */
#define  EXTI_EMR_MR2                        ((uint32_t)0x00000004)        /*!< Event Mask on line 2  */
#define  EXTI_EMR_MR3                        ((uint32_t)0x00000008)        /*!< Event Mask on line 3  */
#define  EXTI_EMR_MR4                        ((uint32_t)0x00000010)        /*!< Event Mask on line 4  */
#define  EXTI_EMR_MR5                        ((uint32_t)0x00000020)        /*!< Event Mask on line 5  */
#define  EXTI_EMR_MR6                        ((uint32_t)0x00000040)        /*!< Event Mask on line 6  */
#define  EXTI_EMR_MR7                        ((uint32_t)0x00000080)        /*!< Event Mask on line 7  */
#define  EXTI_EMR_MR8                        ((uint32_t)0x00000100)        /*!< Event Mask on line 8  */
#define  EXTI_EMR_MR9                        ((uint32_t)0x00000200)        /*!< Event Mask on line 9  */
#define  EXTI_EMR_MR10                       ((uint32_t)0x00000400)        /*!< Event Mask on line 10 */
#define  EXTI_EMR_MR11                       ((uint32_t)0x00000800)        /*!< Event Mask on line 11 */
#define  EXTI_EMR_MR12                       ((uint32_t)0x00001000)        /*!< Event Mask on line 12 */
#define  EXTI_EMR_MR13                       ((uint32_t)0x00002000)        /*!< Event Mask on line 13 */
#define  EXTI_EMR_MR14                       ((uint32_t)0x00004000)        /*!< Event Mask on line 14 */
#define  EXTI_EMR_MR15                       ((uint32_t)0x00008000)        /*!< Event Mask on line 15 */
#define  EXTI_EMR_MR16                       ((uint32_t)0x00010000)        /*!< Event Mask on line 16 */
#define  EXTI_EMR_MR17                       ((uint32_t)0x00020000)        /*!< Event Mask on line 17 */
#define  EXTI_EMR_MR18                       ((uint32_t)0x00040000)        /*!< Event Mask on line 18 */
#define  EXTI_EMR_MR19                       ((uin