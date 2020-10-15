#include "opentelemetry/trace/default_span.h"
#include "opentelemetry/trace/span_context.h"

#include <cstring>
#include <string>

#include <gtest/gtest.h>

namespace
{

using opentelemetry::trace::DefaultSpan;
using opentelemetry::trace::SpanReference;

TEST(DefaultSpanTest, GetContext)
{
  SpanReference span_context = SpanReference(false, false);
  DefaultSpan sp             = DefaultSpan(span_context);
  EXPECT_EQ(span_context, sp.GetContext());
}
}  // namespace
