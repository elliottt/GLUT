/* -----------------------------------------------------------------------------
 *
 * Module      :  GLUT extension support for Graphics.UI.GLUT
 * Copyright   :  (c) Sven Panne 2002-2005
 * License     :  BSD-style (see the file libraries/OpenGL/LICENSE)
 *
 * Maintainer  :  sven.panne@aedion.de
 * Stability   :  provisional
 * Portability :  portable
 *
 * This header should only define preprocessor macros!
 *
 * -------------------------------------------------------------------------- */

#ifndef HSGLUTEXT_H
#define HSGLUTEXT_H

/* NOTE: The macro must immediately start with the foreign declaration,
   otherwise the magic mangler (hack_foreign) in the Hugs build system
   doesn't recognize it. */
#define API_ENTRY_INTERNAL(_entry,_ty,_safety) \
foreign import CALLCONV _safety "dynamic" dyn_/**/_entry :: Graphics.UI.GLUT.Raw.APIEntry.Invoker (_ty) ; \
_entry :: (_ty) ; \
_entry = dyn_/**/_entry ptr_/**/_entry ; \
ptr_/**/_entry :: FunPtr a ; \
ptr_/**/_entry = unsafePerformIO (Graphics.UI.GLUT.Raw.APIEntry.getAPIEntry "_entry") ; \
{-# NOINLINE ptr_/**/_entry #-}

#define API_ENTRY(_entry,_ty) API_ENTRY_INTERNAL(_entry,_ty,unsafe)

#define API_ENTRY_SAFE(_entry,_ty) API_ENTRY_INTERNAL(_entry,_ty,safe)

#endif
